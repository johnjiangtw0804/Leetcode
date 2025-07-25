#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = nums[(int)nums.size() - 1];
        for (int i = (int)nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < 0 || (nums[i] == nums[i + 1]))
            {
                continue;
            }
            sum += nums[i];
        }
        return sum;
    }
};
