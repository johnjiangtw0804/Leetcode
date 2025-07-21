#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char start = s[i];
            int j = i;
            while (j < n && s[j] == s[i])
            {
                j++;
            }
            int len = j - i;
            if (len > 2)
            {
                len = 2;
            }
            for (int count = 0; count < len; count++)
            {
                res.push_back(s[i]);
            }
            i = j - 1;
        }
        return res;
    }
};
