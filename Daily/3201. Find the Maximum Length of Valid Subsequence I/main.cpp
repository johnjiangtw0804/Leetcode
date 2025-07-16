#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // mod = 0 or 1
        // 0 1 => 10...
        // 1 0
        int last_even = 0;
        int last_odd = 0;
        int even = 0;
        int odd =0;
        int res = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                last_odd = last_even + 1;
                even++;
            } else {
                last_even = last_odd + 1;
                odd++;
            }
        }
        return max(max(max(last_even, last_odd), even), odd);
    }
};
