#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int canReachAt = startFuel;
        if (canReachAt >= target)
        {
            return 0;
        }
        int res = INT_MAX;
        long long dp[501];
        memset(dp, -1, sizeof(dp));
        dp[0] = canReachAt;
        // [location, fuel] => [location, fuel], [location, fuel] => 我們只要一個對吧
        // dp[# fuel] = location
        // dp[i] := how far can I reach
        // when I have a station =>
        for (int i = 0; i < (int)stations.size(); i++)
        {
            int location = stations[i][0];
            int fuel = stations[i][1];
            // all the previous stations that can reach here can get a fuel and go somewhere further
            // ----
            //  x-------(replaced)
            //    x-------
            // for all the dp that can reach the location
            for (int i = 499; i >= 0; i--)
            {
                if (dp[i] >= location)
                {
                    dp[i + 1] = max(dp[i] * 1ll + fuel, dp[i + 1]);
                }
            }
        }
        int i = 0;
        for (int fuel : dp)
        {
            if (fuel >= target)
            {
                return i;
            }
            i++;
        }

        // ...>
        return -1;
    }
};

int main()
{
Input:
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    Solution s;
    cout << s.minRefuelStops(target, startFuel, stations) << endl;
}
