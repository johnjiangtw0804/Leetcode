#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        vector<int> res(nums.size(), -1);
        int n = nums.size();
        // 現在要求的是 minimum windowsize with maximum orsum
        // 你要觀察窗口的滑動方向來做出 Ｏ(n)
        // 這題窗口是往右邊飄
        // 那你應該往左邊滑
        int j = n - 1;
        vector<int> bitCounts(32, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int num = nums[i];
            for (int k = 0; k < 32; k++)
            {
                bitCounts[k] += ((num >> k) & 1);
            }

            while (i < j && isOKToRemove(bitCounts, nums[j]))
            {
                for (int k = 0; k < 32; k++)
                {
                    bitCounts[k] -= ((nums[j] >> k) & 1);
                }
                j--;
            }
            res[i] = j - i + 1;
        }

        return res;
    }
    bool isOKToRemove(vector<int> &bitCounts, int num)
    {
        for (int k = 0; k < 32; k++)
        {
            if (bitCounts[k] == 1 && ((num >> k) & 1) == 1)
            {
                return false;
            }
        }
        return true;
    }
};
