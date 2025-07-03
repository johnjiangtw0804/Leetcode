#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n){
        // 1 <= strs.length <= 600
        // 1 <= strs[i].length <= 100
        // m => 0
        // n => 1
        // m and n are both pretty low
        int s = strs.size();
        int res = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // dp[0:m-zeros][0:n-ones]
        for (int i = 0; i < (int)strs.size(); i++)
        {
            // 10
            string str = strs[i];
            int ones = 0;
            int zeros = 0;
            for (char c : str) {
                if (c == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }

            // dp[j][k]
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    // In 0/1 Knapsack, forward order is unsafe because:
                    // You can “reuse” an updated dp in the same iteration → you’d double - count the same item.
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
                    res = max(dp[j][k], res);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"10", "0001", "111001", "1", "0" };
    int m = 5;
    int n = 3;
    cout << ((s.findMaxForm(strs, 5, 3) == 4) ? "Correct" : "False") << endl;
}
