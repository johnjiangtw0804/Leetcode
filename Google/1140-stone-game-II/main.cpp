#include <iostream>
using namespace std;
class Solution {
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] += suffix[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        function<int(int, int)> helper = [&](int i, int M)
        {
            int scores = 0, res = 0;
            if (dp[i][M] != 0)
            {
                return dp[i][M];
            }
            // 2n * how many differ i M => n * n
            for (int x = 1; x <= 2 * M; x++)
            {
                if (i + x - 1 >= n)
                {
                    break;
                }
                scores += piles[i + x - 1];
                // rest of scores - bobs score need to be maximized
                res = max(scores + suffix[i + x] - helper(i + x, max(M, x)), res);
            }
            return dp[i][M] = res;
        };
        return helper(0, 1);
    }
};
