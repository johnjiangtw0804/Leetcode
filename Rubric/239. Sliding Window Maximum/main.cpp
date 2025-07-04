#include <vector>
#include <iostream>
#include <deque>

using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        int n = nums.size();
        // [1, 3 -1 -3]
        // increasing stack 1, 3 <= [-1] => -1 這有產生個 property => stack 的頭是最小值
        // decreasing stack 1 <= 3 => 3 <= -1, 3, -1 <= -3 => 3 -1 -3 => 這裡產生另個 property => stack 的頭是最大
        // in here, we need decreasing stack
        deque<int> deq;
        for (int i = 0; i < n; i++) {
            // we need to pop when the diff is >= k
            while (deq.size() > 0 && (i - deq.front()) >= k) {
                deq.pop_front();
            }

            while (deq.size() > 0 && nums[deq.back()] < nums[i])
            {
                deq.pop_back();
            }
            deq.push_back(i);
            if (i >= k -1) {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};


int main () {
    Solution s;
    vector<int>nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for (int temp : res) {
        cout << temp << endl;
    }
}
