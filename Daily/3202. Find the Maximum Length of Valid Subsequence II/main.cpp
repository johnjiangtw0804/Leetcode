#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int dp[k + 1][k + 1];
        memset(dp, INT_MIN / 2, sizeof(dp));

        // 1...x: let x be the current element
        // subsequent # has the same mod
        // dp[ending at something][remainder]
        // when we see x
        // dp[y][(y+x) % k] its length can be used to increment
        // dp[x%k][(y+x) % k] = (dp[y][(y+x) % k] + 1, dp[x%k][(y+x)%k])
        int res = 1;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            int x = nums[i];
            for (int y = 0; y < k; y++)
            {
                if ((dp[y][(x + y) % k]) == INT_MIN / 2)
                    continue;
                dp[x % k][(x + y) % k] = max(dp[y][(x + y) % k] + 1, dp[x % k][(x + y) % k]);
                res = max(res, dp[x % k][(y + x) % k]);
            }
            if (dp[x % k][x % k] == -1)
            {
                dp[x % k][x % k] = 1;
            }
        }
        return res == 1 ? 0 : res;
    }
};
