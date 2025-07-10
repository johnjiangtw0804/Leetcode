#include <vector>

using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        if (startTime.size() == 0)
        {
            return eventTime;
        }

        startTime.emplace_back(eventTime);
        endTime.emplace_back(eventTime);
        startTime.emplace(startTime.begin(), 0);
        endTime.emplace(endTime.begin(), 0);

        int n = startTime.size();
        vector<int> spotsLeft;
        for (int i = n - 2; i >= 0; i--)
        {
            int end = endTime[i];
            int nexStart = startTime[i + 1];
            int freeTime = nexStart - end;
            spotsLeft.push_back(freeTime);
        }
        reverse(spotsLeft.begin(), spotsLeft.end());
        vector<int> spotsLeftBack(spotsLeft.size(), 0);
        vector<int> spotsLeftFront(spotsLeft.size(), 0);

        int currMax = 0;
        for (int i = (int)spotsLeft.size() - 1; i >= 0; i--)
        {
            currMax = max(spotsLeft[i], currMax);
            spotsLeftBack[i] = currMax;
        }
        currMax = 0;
        for (int i = 0; i < (int)spotsLeft.size(); i++)
        {
            spotsLeftFront[i] = currMax;
            currMax = max(spotsLeft[i], currMax);
        }
        int res = INT_MIN;
        for (int i = 0; i < n - 2; i++)
        {
            int nextStart = startTime[i + 1];
            int nextEnd = endTime[i + 1];
            int nextDuration = nextEnd - nextStart;
            if (i + 2 < (int)spotsLeft.size() && spotsLeftBack[i + 2] >= nextDuration ||
             (spotsLeftFront[i] >= nextDuration))
            {
                int nextNextStart = startTime[i + 2];
                res = max(res, nextNextStart - endTime[i]);
            }
            else
            {
                res = max(res, startTime[i + 2] - endTime[i] - (nextEnd - nextStart));
            }
        }
        return res;
    }
};
