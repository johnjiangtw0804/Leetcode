#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // dp[r][i][j]: maximum scores we can reach at row i and robot 1 at i and robot 2 at j
        // we need to remember the state of each i and j
        // dp[r][i][j]: dp[r-1][a][b] + grid[r][i] + grid[r][j], if i == j only add grid[i][j] once
        // what are the dp[r-1][a][b]?
        // a => (i, i -1, or i + 1)
        // b => (j, j-1 or j + 1) => we can get all the pairs
        // 重點: 到不了的 INT_MIN
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        int res = 0;
        for (int r = 1; r < m; r++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int a = -1; a <= 1; a++)
                    {
                        for (int b = -1; b <= 1; b++)
                        {
                            if (i + a < 0 || i + a >= n || j + b < 0 || j + b >= n)
                            {
                                continue;
                            }
                            if (i != j)
                            {
                                dp[r][i][j] = max(dp[r][i][j], dp[r - 1][i + a][j + b] + grid[r][i] + grid[r][j]);
                            }
                            else
                            {
                                dp[r][i][j] = max(dp[r][i][j], dp[r - 1][i + a][j + b] + grid[r][j]);
                            }
                        }
                    }
                    res = max(res, dp[r][i][j]);
                }
            }
        }
        return res;
    }
};
