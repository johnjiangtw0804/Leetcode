#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0) {
            return 0;
        }
        unordered_set<char> seen;

        int fast = 0;
        int slow = 0;
        int n = s.size();
        int res = INT_MIN/2;
        while (fast < n) {
            char c = s[fast];

            while (slow < fast && seen.find(c) != seen.end()) {
                seen.erase(s[slow]);
                slow++;
            }
            res = max(res, fast - slow+1);
            seen.insert(s[fast]);
            fast++;
        }
        return res;
    }
};

int main() {
    Solution s;
    string example1 ="abcabcbb";
    cout << (s.lengthOfLongestSubstring(example1) == 3) << endl; // 1
}
