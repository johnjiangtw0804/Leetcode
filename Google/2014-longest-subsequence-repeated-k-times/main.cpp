#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // 2 <= n, k <= 2000
    // b4 [a lot of thing ] => k to filter => char needs to be at least count of k
    // 2 <= n < k * 8
    // 如果 subsequence  >= 8 => 長度會大於 n
    // |subsequence| <= 7
    // subsequence 的可能性 ? 由哪些字母組成？
    // {a,b,c} ... 但是這些字母頻次需要 >= k
    // aaaaa..k
    // bbbbb..
    // 但是 k * 8 > n =>  |{abc}| <= 7
    vector<char> filteredS;
    unordered_set<char> filteredSet;
    int k;
    string res = "";
    string longestSubsequenceRepeatedK(string s, int k)
    {
        this->k = k;
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        for (char c : s)
        {
            if (freq[c - 'a'] >= k)
            {
                filteredS.push_back(c);
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] >= k)
            {
                filteredSet.insert('a' + i);
            }
        }
        string temp = "";
        dfs(temp);
        return res;
    }

    // can we just guess the subsequence? 用所有可能的字母
    void dfs(string &temp)
    {
        // 減掉
        if (!checkOK(temp))
        {
            return;
        }
        if (temp.size() > res.size() ||
            (temp.size() == res.size() && temp > res))
        {
            res = temp;
        }
        if (temp.size() > 7)
        {
            return;
        }

        // how we build the subsequence is an issue
        // 應該只能 filteresS 裡面的來 build
        // 7^7
        for (char c : filteredSet)
        {
            temp.push_back(c);
            dfs(temp);
            temp.pop_back();
        }
    }

    // 1600
    bool checkOK(string &temp)
    {
        if (temp == "")
        {
            return true;
        }
        int j = 0;
        int counter = 0;
        for (char c : filteredS)
        {
            if (c == temp[j])
            {
                j++;
                if (j == (int)temp.size())
                {
                    j = 0;
                    counter++;
                }
            }
        }
        if (counter >= k)
        {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::string s = "letsleetcode";
    int k = 2;
    std::cout << ((sol.longestSubsequenceRepeatedK(s, k) == "let") ? "true" : "false") << std::endl;
    return 0;
}
