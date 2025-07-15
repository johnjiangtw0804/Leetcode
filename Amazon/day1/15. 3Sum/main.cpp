#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] > 0)
            {
                break;
            }
            int slow = i + 1;
            int fast = n - 1;
            while (slow < fast)
            {
                int sum = nums[i] + nums[slow] + nums[fast];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[slow], nums[fast]});
                    while (slow < fast && nums[slow] == nums[slow + 1])
                        slow++;
                    while (slow < fast && nums[fast] == nums[fast - 1])
                        fast--;
                    slow++;
                    fast--;
                }
                else
                {
                    if (sum > 0)
                    {
                        fast--;
                    }
                    else
                    {
                        slow++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> example1 = {-1,0,1,2,-1,-4};
    vector<vector<int>> sol1 = s.threeSum(example1);
    for (auto a : sol1) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
}
