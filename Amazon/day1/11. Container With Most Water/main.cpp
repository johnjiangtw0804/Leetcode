#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int end = height.size() -1;
        int start = 0;
        // 2e9

        while (start < end) {
            int h1 = height[start];
            int h2 = height[end];
            res = max(res, (end - start) * min(h1, h2));
            if (h1 < h2) {
                start++;
            } else if (h2 < h1) {
                end--;
            } else {
                start++;
                end--;
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<int> example1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << s.maxArea(example1) << endl;;
}
