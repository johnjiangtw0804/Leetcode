#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        // [(i), (j), len]
        // try to find two indices in len => swap/not swap
        int memo[31][31][31];
        memset(memo, -1, sizeof(memo));
        function<bool(int, int, int)> helper = [&](int i, int j, int len) -> bool
        {
            if (len == 1)
            {
                if (s1[i] == s2[j])
                {
                    return true;
                }
                return false;
            }

            if (memo[i][j][len] != -1)
            {
                return memo[i][j][len];
            }
            string s1_sub = s1.substr(i, len);
            string s2_sub = s2.substr(j, len);
            sort(s1_sub.begin(), s1_sub.end());
            sort(s2_sub.begin(), s2_sub.end());
            if (s1_sub != s2_sub)
                return memo[i][j][len] = 0;
            // i ---- len
            for (int firstHalfLen = 1; firstHalfLen < len; firstHalfLen++)
            {
                // i --k k+1---len
                // no swap
                // L R vs L R
                if (helper(i, j, firstHalfLen) && helper(i + firstHalfLen, j + firstHalfLen, len - firstHalfLen))
                {
                    return memo[i][j][len] = true;
                }
                // swap
                // R L vs L R
                if (helper(i, j + len - firstHalfLen, firstHalfLen) && helper(i + firstHalfLen, j, len - firstHalfLen))
                {
                    return memo[i][j][len] = true;
                }
            }
            return memo[i][j][len] = false;
        };
        int n = s1.size();
        return helper(0, 0, n);
    }
};
