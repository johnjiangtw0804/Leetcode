#include <iostream>
#include <vector>
#include <limits>
#include <climits>

using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // word1 = "horse", word2 = "ros"
        // 0 <= word1.length, word2.length <= 500
        // word1 => r
        // [horse]....=> r
        // dp[i][j]: min # of ops to make word1[:i] to word2[:j]
        // Insert a character h      ros dp[i][j]
        // Delete a character
        // Replace a character
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            if (i == 1)
            {
                dp[0][1] = 1;
            }
            else
            {
                dp[0][i] = dp[0][i - 1] + 1; // insert
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                dp[1][0] = 1;
            }
            else
            {
                dp[i][0] = dp[i - 1][0] + 1; // delete
            }
        }
        // 1r  ro
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // replace [i-1][j-1] + 1
                // delete [i-1][j] +1
                // insert [i][j-1] + 1
                dp[i][j] = min(min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1), dp[i][j]);
            }
        }
        // cout << dp[n][m];
        return dp[n][m];
    }
};

int main () {
    Solution s;
    cout << ((s.minDistance("horse", "ros") == 3) ? "Correct" : "False") << endl;
}
