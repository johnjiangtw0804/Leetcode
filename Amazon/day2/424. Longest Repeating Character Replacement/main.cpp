#include <vector>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int res = 0;
        for (char fixed_char = 'A'; fixed_char <= 'Z'; fixed_char++)
        {
            int ops = 0;
            int slow = 0;
            int fast = 0;
            while (fast < n)
            {
                char c = s[fast];
                if (c != fixed_char)
                {
                    if (ops >= k)
                    {
                        while (slow <= fast && ops >= k)
                        {
                            if (s[slow] != fixed_char)
                            {
                                ops--;
                            }
                            slow++;
                        }
                    }
                    ops++;
                }
                res = max(res, fast - slow + 1);
                fast++;
            }
        }
        return res;
    }
};
