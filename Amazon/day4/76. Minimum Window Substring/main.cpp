#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> t_freq_count;
        for (char c : t)
        {
            t_freq_count[c]++;
        }
        int slow = 0, fast = 0, n = s.size();
        pair<int, int> res = {INT_MAX, INT_MAX};
        int matched_count = 0;
        int match_target = t_freq_count.size();
        while (fast < n)
        {
            char c = s[fast];
            if (t_freq_count.contains(c))
            {
                t_freq_count[c]--;
                if (t_freq_count[c] == 0)
                    matched_count++;
            }
            if (matched_count >= match_target)
            {
                while (slow <= fast && matched_count == match_target)
                {
                    if ((fast - slow + 1) < res.second)
                    {
                        res.first = slow;
                        res.second = fast - slow + 1;
                    }
                    if (t_freq_count.contains(s[slow]))
                    {
                        if (t_freq_count[s[slow]] == 0)
                            matched_count--;
                        t_freq_count[s[slow]]++;
                    }
                    slow++;
                }
            }
            fast++;
        }
        if (res.first == INT_MAX)
        {
            return "";
        }
        return s.substr(res.first, res.second);
    }
};
