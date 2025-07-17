#include <vector>
#include <algorithm>

using namespace std;

#define PII pair<int, int>
class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        vector<PII> pairs;
        for (auto interval : intervals)
        {
            PII enter = PII(interval[0], +1);
            PII end = PII(interval[1], -1);
            pairs.emplace_back(enter);
            pairs.emplace_back(end);
        }
        sort(pairs.begin(), pairs.end());

        int rooms = 0;
        int res = 0;
        for (PII pair : pairs)
        {
            rooms += pair.second;
            res = max(res, rooms);
        }
        return res;
    }
};
