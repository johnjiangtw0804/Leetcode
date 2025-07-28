#include <vector>

using namespace std;

class Solution
{
public:
    int res = 0;
    int max;
    int countMaxOrSubsets(vector<int> &nums)
    {
        max = 0;
        for (int num : nums)
        {
            max |= num;
        }
        DFS(0, nums, 0);
        return res;
    }
    void DFS(int i, const vector<int> &nums, int currentSum)
    {
        if (i == (int)nums.size())
        {
            if (currentSum == max)
            {
                res++;
            }
            return;
        }
        DFS(i + 1, nums, currentSum | nums[i]);
        DFS(i + 1, nums, currentSum);
    }
};
