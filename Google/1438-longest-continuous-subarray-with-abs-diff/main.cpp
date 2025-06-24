#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int res = 0, slow = 0, fast = 0;
        int n = nums.size();
        deque<int> increasing;
        deque<int> decreasing;
        // [sorted window]
        // [min<<[....]<<max]
        // when we move our slow we dont wanna find the thing and pop it, right?
        // we are just tring to know the first min and next possible min... and a max and the next possible max
        while (fast < n) {
            int current = nums[fast];
            // strictly decreasing
            while (decreasing.size() != 0 && nums[decreasing.back()] <= current) {
                decreasing.pop_back();
            }
            decreasing.push_back(fast);
            while (increasing.size() != 0 && nums[increasing.back()] >= current) {
                increasing.pop_back();
            }
            increasing.push_back(fast);
            // not ok
            if ((nums[decreasing.front()] - nums[increasing.front()]) > limit) {
                // try to move my slow so that my min becomes larger
                while (slow < fast && (nums[decreasing.front()] - nums[increasing.front()] > limit)) {
                    if (slow == decreasing.front()) {
                        decreasing.pop_front();
                    }
                    if (slow == increasing.front()) {
                        increasing.pop_front();
                    }
                    slow++;
                }
            }
            res = max(res, fast - slow + 1);
            fast++;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    int res1= s.longestSubarray(nums, limit);
    cout << ((res1 == 2) ? "true" : ("false " + to_string(res1))) << endl;
}
