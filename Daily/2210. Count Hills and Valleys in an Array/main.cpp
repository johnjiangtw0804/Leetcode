#include <vector>

using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int N = nums.size();
        // 主要原因是他有一樣的
        int prev = nums[0];
        int res = 0;
        for (int i = 1; i < N - 1; i++)
        {
            while (i < N - 1 && nums[i] == prev)
            {
                i++;
            }
            while (i < N - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
            // C++ 還是用 .at() 不然 out of bound 不會報錯
            if (i < N - 1 && nums[i] > prev && nums[i] > nums[i + 1])
            {
                res++;
            }
            if (i < N - 1 && nums[i] < prev && nums[i] < nums[i + 1])
            {
                res++;
            }
            prev = nums[i];
        }
        return res;
    }
};
