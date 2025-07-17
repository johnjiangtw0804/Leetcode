#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
        {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> prevtInterval = intervals[0];
        for (int i = 1; i < (int)intervals.size(); i++)
        {
            if (prevtInterval[1] >= intervals[i][0])
            {
                prevtInterval[1] = max(prevtInterval[1], intervals[i][1]);
            }
            else
            {
                res.push_back(prevtInterval);
                prevtInterval = intervals[i];
            }
        }
        res.push_back(prevtInterval);
        return res;
    }
};
