#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> Stack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                Stack.push(c);
                continue;
            }
            if (c == ')')
            {
                if (Stack.empty())
                {
                    return false;
                }
                if (Stack.top() == '(')
                {
                    Stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (c == '}')
            {
                if (Stack.empty())
                {
                    return false;
                }
                if (Stack.top() == '{')
                {
                    Stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (c == ']')
            {
                if (Stack.empty())
                {
                    return false;
                }
                if (Stack.top() == '[')
                {
                    Stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return Stack.empty();
    }
};
