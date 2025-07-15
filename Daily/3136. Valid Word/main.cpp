#include <iostream>

using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() >= 3 && hasOnlyEnglishAndAlpha(word) && hasVowel(word) && hasConsonant(word))
        {
            return true;
        }
        return false;
    }
    bool hasOnlyEnglishAndAlpha(const string &s) const
    {
        for (const char &c : s)
        {
            if (!isalpha(c) && !isdigit(c))
            {
                return false;
            }
        }
        return true;
    }
    bool hasVowel(const string &s) const
    {
        for (const char &c : s)
        {
            char l_c = tolower(c);
            if (l_c == 'a' || l_c == 'e' || l_c == 'i' || l_c == 'o' || l_c == 'u')
            {
                return true;
            }
        }
        return false;
    }
    bool hasConsonant(const string &s) const
    {
        for (const char &c : s)
        {
            char l_c = tolower(c);
            if (isalpha(l_c) && l_c != 'a' && l_c != 'e' && l_c != 'i' && l_c != 'o' && l_c != 'u')
            {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    string test1 = "234Adas";

    cout << (s.isValid(test1)) << endl;
}
