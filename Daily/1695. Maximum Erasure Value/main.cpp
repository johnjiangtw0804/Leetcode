#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // sum of unique subarrays
        int N = nums.size();
        int slow = 0;
        int fast = 0;
        int res = INT_MIN;
        unordered_set<int> seen;
        int current_sum = 0;
        while (fast < N) {
            int curr = nums[fast];
            if (seen.find(curr) != seen.end()) {
                while(slow < fast && nums[slow] != curr) {
                    int rem = nums[slow];
                    current_sum -= rem;
                    seen.erase(rem);
                    slow++;
                }
                int rem = nums[slow];
                current_sum -= rem;
                seen.erase(rem);
                slow++;
            }
            current_sum += curr;
            res = max(current_sum, res);
            seen.insert(curr);
            fast++;
        }
        return res;
    }
};
