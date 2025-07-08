#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class HtmlParser {
   public:
      vector<string> getUrls(string url);
};

class Solution
{
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser)
    {
        function<string(string)> getHostName = [](string url) -> string
        {
            // http://
            size_t loc = url.find("/", 7);
            return (loc == string::npos) ? url.substr(7) : url.substr(7, loc - 7);
        };
        string hostName = getHostName(startUrl);
        cout << hostName << endl;
        unordered_set<string> seen;
        queue<string> q;
        q.push(startUrl);
        seen.insert(startUrl);

        while (q.size() > 0)
        {
            int lvl = q.size();
            for (int l = 0; l < lvl; l++)
            {
                string url = q.front();
                q.pop();
                vector<string> crawled = htmlParser.getUrls(url);
                for (string c : crawled)
                {
                    if (getHostName(c) != hostName)
                    {
                        continue;
                    }

                    // 找到過
                    if (seen.find(c) != seen.end())
                    {
                        continue;
                    }
                    q.push(c);
                    seen.insert(c);
                }
            }
        }
        return vector<string>(seen.begin(), seen.end());
    }
};
