#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int n = s.size();
        int i = n - 1;

        while (i >= 0)
        {
            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ')
                i--;
            if (i < 0)
                break;

            int j = i;
            // Find the start of the word
            while (j >= 0 && s[j] != ' ')
                j--;

            // Append the word
            res.append(s.substr(j + 1, i - j));
            res.push_back(' ');

            i = j - 1;
        }

        if (!res.empty())
            res.pop_back(); // Remove last space
        return res;
    }
};
