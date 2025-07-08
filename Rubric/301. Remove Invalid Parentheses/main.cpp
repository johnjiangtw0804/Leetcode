#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> res;
        queue<string> q;
        q.push(s);
        unordered_set<string> seen;
        seen.insert(s);
        bool notFound = true;
        while (q.size() > 0 && notFound)
        {
            int lvl = q.size();
            for (int l = 0; l < lvl; l++)
            {
                string current = q.front();
                q.pop();
                if (isValid(current))
                {
                    notFound = false;
                    res.push_back(current);
                }
                for (int j = 0; j < (int)current.size(); j++)
                {
                    char c = current[j];
                    if (isalpha(c))
                    {
                        continue;
                    }
                    // remove
                    string rem = current.substr(0, j) + current.substr(j + 1);
                    if (seen.find(rem) != seen.end())
                    {
                        continue;
                    }
                    seen.insert(rem);
                    q.push(rem);
                    // no remove
                }
            }
        }
        // ()

        return res;
    }

    bool isValid(string s)
    {
        stack<char> stack;
        for (char c : s)
        {
            if (c == '(')
            {
                stack.push(')');
            }
            else if (c == ')')
            {
                if (stack.size() > 0 && stack.top() == ')')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stack.size() == 0;
    }
};
