#include <iostream>
using namespace std;
class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int count = 0;
        // I think we should always take the zeros adding a 1 cause more no matter what
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            count += s[i] == '0' ? 1 : 0;
        }
        int limit = 32 - __builtin_clz(k); // to handle overflow
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > limit) // we dont want the power to get to too much
            {
                break;
            }
            char c = s[n - i - 1];
            if (c == '1')
            {
                int added = 1L << i;
                if (total + added <= k)
                {
                    total += added;
                    count++;
                }
            }
        }
        return count;
    }
};
