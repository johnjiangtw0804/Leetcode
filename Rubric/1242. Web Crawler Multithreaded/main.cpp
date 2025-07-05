#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <thread>

using namespace std;
class HtmlParser
{
public:
    virtual vector<string> getUrls(string url) = 0;
};

class FakeHtmlParse: HtmlParser {
    vector<string> getUrls(string url) {
        if (url == "http://news.yahoo.com")
        {
            return {"http://news.yahoo.com/news", "http://news.yahoo.com/us"};
        }
        else if (url == "http://news.yahoo.com/news")
        {
            return {"http://news.yahoo.com/news/topics/"};
        }
        else
        {
            return {};
        }
    }
};

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution
{
private:
    unordered_set<string> visited;
    queue<string> q;
    mutex m;
    condition_variable cv;

public:
    vector<string> crawl(string startUrl, HtmlParser &htmlParser)
    {
        function<string(string)> getHostName = [](const string &url)
        {
            size_t pos = url.find("/", 7); // http://(host)/
            return pos == string::npos ? url : url.substr(0, pos);
        };

        string startHostName = getHostName(startUrl);
        q.push(startUrl);
        visited.insert(startUrl);

        // thread is going to do the following:
        // 1. crawl the given url
        // 2. get the urls and check for hostname
        // 3. if match == startHostName && not visited => store in the queue
        int activeWorkers = 0;
        function<void()> worker = [&]()
        {
            while (true)
            {
                string crawlingUrl;
                {
                    unique_lock<mutex> lock(m);

                    // wait until
                    // 這還滿重要 wait until q.size() > 0 or we have no workers left
                    // 這樣 notify 才會起來因為 q.size() 不可能有東西了
                    cv.wait(lock, [&]()
                            { return q.size() > 0 || activeWorkers == 0; });

                    if (q.size() == 0 && activeWorkers == 0)
                    {
                        break;
                    }
                    crawlingUrl = q.front();
                    q.pop();
                    activeWorkers++;
                }

                vector<string> crawledUrls = htmlParser.getUrls(crawlingUrl);
                {
                    lock_guard<mutex> mylockGuard(m);
                    for (const string &c : crawledUrls)
                    {
                        if (getHostName(c) == startHostName && visited.insert(c).second)
                        {
                            q.push(c);
                            cv.notify_one();
                        }
                    }
                    activeWorkers--;
                    if (activeWorkers == 0 && q.empty())
                    {
                        cv.notify_all();
                    }
                }
            }
        };
        vector<thread> threadpools;
        for (int i = 0; i < 20; i++)
        {
            threadpools.emplace_back(worker);
        }

        for (int i = 0; i < 20; i++)
        {
            threadpools[i].join();
        }
        return vector<string>(visited.begin(), visited.end());
    }
};
