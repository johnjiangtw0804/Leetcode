#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> pairs;
        for (auto f : freq) {
            pairs.push_back(f);
        }
        auto comp = [](const pair<int, int> &p1, const pair<int, int> &p2)
        {
            return p1.second > p2.second;
        };
        sort(pairs.begin(), pairs.end(), comp);
        for (int i = 0; i < k; i++) {
            res.push_back(pairs[i].first);
        }
        return res;
    }
};
