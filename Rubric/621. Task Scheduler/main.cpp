#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
using PCI = pair<char, int>;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        auto comp = [](const PCI& a, const PCI& b) {
            return a.second < b.second; // pq less => max queue
        };
        priority_queue<PCI, vector<PCI>, decltype(comp)> pq(comp);
        unordered_map<char, int> freq;
         for (char t : tasks)
        {
            freq[t]++;
        }

        for (auto[task, count] : freq) {
            pq.push(PCI(task, count));
        }
        int intervals = 0;
        queue<PCI> cooldown;
        while (pq.size() > 0 || cooldown.size() > 0)
        {
            while (cooldown.size() > 0 && (intervals - cooldown.front().second -1) >= n) {
                auto popped = cooldown.front(); cooldown.pop();
                pq.push(PCI(popped.first, freq[popped.first]));
            }
            if (pq.size() > 0) {
                PCI popped = pq.top(); pq.pop();
                // done once
                popped.second -= 1;
                freq[popped.first] -=1;

                // still need to be executed
                if (freq[popped.first] > 0) {
                    cooldown.push(PCI(popped.first, intervals));
                }
            }

            intervals++;
        }

        return intervals;
    }
};

int main () {
    Solution s;
    vector<char> tasks = {'A','A','A','B','B','B'};

    cout << s.leastInterval(tasks, 2) << endl;
}
