#include <vector>

using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // ab
        // ba
        // 唯一有可能產生分歧的結果
        // aba
        // bab
        // S|aba|S
        // S|bab| => remove higher score one => S|a|S or S|b|S 剩下的字母都是一樣的
        int res = 0;
        int N = s.size();
        vector<char> pair = {'a', 'b'};
        if (x < y) {
            swap(x,y);
            pair = {'b', 'a'};
        }
        vector<char> Stack;
        for (int i = 0; i < N; i++) {
            char curr = s[i];
            if (Stack.size() > 0 && Stack.back() == pair[0] && curr == pair[1]) {
                Stack.pop_back();
                res += x;
                continue;
            }
            Stack.push_back(curr);
        }
        vector<int> temp(Stack.begin(), Stack.end());
        swap(pair[0], pair[1]);
        Stack.clear();
        for (int i = 0; i < (int)temp.size(); i++) {
            char curr = temp[i];
            if (Stack.size() > 0 && Stack.back() == pair[0] && curr == pair[1]) {
                Stack.pop_back();
                res += y;
                continue;
            }
            Stack.push_back(curr);
        }

        return res;
    }
};
