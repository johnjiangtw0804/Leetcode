#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 1 <= nums.length <= 200
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        // 0 1 2 3
        for (int i = 0; i < n - 3; i++)
        {
            // 有點 tricky 要 skip i and j
            if (i >= 1 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++)
            {
                if ((j != i + 1) && nums[j] == nums[j - 1])
                {
                    continue;
                }
                long long twoSumTarget = target - (nums[i] * 1ll + nums[j]);
                int start = j + 1;
                int end = n - 1;
                while (start < end)
                {
                    if (nums[start] + nums[end] == twoSumTarget)
                    {
                        res.emplace(res.end(), vector<int>{nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;

                        // 這邊也要特別處理
                        while (start < end && nums[start] == nums[start - 1])
                        {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end + 1])
                        {
                            end--;
                        }
                    }
                    else if ((nums[start] + nums[end]) < twoSumTarget)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> input1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = s.fourSum(input1, 0);
    for (const vector<int>& v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    // Output: [ [ -2, -1, 0 0 1, 2 ],
    //        [ -2, 0, 0, 2 ], [ -1, 0, 0, 1 ] ] -2 -1 0 (0  0 2 2)
}
