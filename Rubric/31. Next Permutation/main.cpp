#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums){
        // 1 <= nums.length <= 100
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            int diff = INT_MAX/2;
            int nextGreaterIdx = -1;
            for (int j = i + 1; j <= n-1; j++) {
                int nextGreater = nums[j];
                if (diff > abs(nums[i] -nums[j]) && (nums[j] > nums[i])) {
                    diff = abs(nums[i] -nums[j]);
                    nextGreaterIdx = j;
                }
            }
            if (nextGreaterIdx == -1)
            {
                continue;
            }
            swap(nums[i], nums[nextGreaterIdx]);
            sort(nums.begin() + i+1, nums.end());
            return;
        }

        sort(nums.begin(), nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    s.nextPermutation(nums1);
    cout << ((nums1 == vector<int>{1,3,2}) ? "True" : "False") << endl;
    vector<int> nums2 = {3, 2, 1};
    s.nextPermutation(nums2);
    cout << ((nums2 == vector<int>{1, 2, 3}) ? "True" : "False") << endl;

    vector<int> nums3 = {1, 1, 5};
    s.nextPermutation(nums3);
    cout << ((nums3 == vector<int>{1, 5, 1}) ? "True" : "False") << endl;
}
