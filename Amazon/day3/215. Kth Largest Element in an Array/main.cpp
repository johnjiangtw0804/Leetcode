#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
        int n = nums.size();
        // k-- 去配合 index
        return quickSelect(nums, 0, n - 1, k - 1);
    }
    int quickSelect(vector<int> &nums, int left, int right, int k)
    {
        int n = right - left + 1;
        if (left == right)
            return nums[left];
        int pivot_idx = rand() % n + left;

        int pivot = nums[pivot_idx];
        int stored_left = left;
        swap(nums[pivot_idx], nums[right]);
        for (int i = left; i <= right - 1; i++)
        {
            if (nums[i] >= pivot)
            {
                swap(nums[stored_left], nums[i]);
                stored_left++;
            }
        }
        swap(nums[stored_left], nums[right]);
        if (k <= stored_left)
        {
            while (left < stored_left && nums[stored_left] == nums[stored_left - 1])
            {
                // 以免減過頭
                if (stored_left == k)
                    return pivot;
                stored_left--;
            }
            return quickSelect(nums, left, stored_left, k);
        }
        return quickSelect(nums, stored_left + 1, right, k);
    }
};
