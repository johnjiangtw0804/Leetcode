#include <functional>
#include <iostream>

using namespace std;

class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + stoneValue[i];
        }
        helper(0, n, dp, stoneValue, suffix);

        if ((suffix[0] - dp[0]) == dp[0])
        {
            return "Tie";
        }
        return (suffix[0] - dp[0]) < dp[0] ? "Alice" : "Bob";
    }
    int helper(int i, const int &n, vector<int> &dp, vector<int> &stoneValue, const vector<int> &suffix)
    {
        if (dp[i] != -1)
        {
            return dp[i];
        }
        if (i == n)
        {
            return dp[n];
        }
        int scores = 0;
        int res = INT_MIN / 2;
        for (int x = 1; x <= 3; x++)
        {
            if (i + x - 1 >= n)
            {
                break;
            }
            scores += stoneValue[i + x - 1];
            res = max(res, scores + (suffix[i + x] - (helper(i + x, n, dp, stoneValue, suffix))));
        }
        return dp[i] = res;
    }
};

int main () {
    Solution s;
    vector<int> stoneValue = {1, 2, 3, 7 };
    string res = s.stoneGameIII(stoneValue);
    cout << ((res == "Bob") ? "true" : ("false " + res))<< endl;
}
