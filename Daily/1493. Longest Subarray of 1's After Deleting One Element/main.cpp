#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int slow = 0;
        int fast = 0;
        int n = nums.size();
        int remove_count = 0;
        while(fast < n) {
            if (nums[fast] == 0) {
                while (slow < fast && remove_count == 1) {
                    if (nums[slow] == 0) {
                        remove_count--;
                    }
                    slow++;
                }
                remove_count++;
            }
            res = max(res, fast - slow + 1 - (remove_count == 0 ? 1 : remove_count));
            fast++;
        }
        return res;
    }
};
