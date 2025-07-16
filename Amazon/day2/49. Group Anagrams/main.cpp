#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> Map;
        for (string str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            Map[copy].push_back(str);
        }

        for (auto[k, v] : Map) {
            res.push_back(v);
        }
        return res;
    }
};
