#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
using ll = long long;

class Solution
{
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k){
        // 1 <= nums1.length, nums2.length <= 5 * 10^4
        // [2, 5], [3, 4]
        int n2 = nums2.size();
        int n1 = nums1.size();
        ll start = min(min(nums1[0] * nums2[0], nums1[0] * nums2[n2-1]), min(nums1[n1-1] * nums2[0], nums1[n1-1] * nums2[n2-1]));
        ll end = max(max(nums1[0] * nums2[0], nums1[0] * nums2[n2 - 1]), max(nums1[n1 - 1] * nums2[0], nums1[n1 - 1] * nums2[n2 - 1]));

        function<bool(ll)> isOK = [&](ll mid) {
            ll total = 0;
            for (int i = 0; i < n1; i++) {
                int fixed = nums1[i];
                // try to find the boundary that nums[i] * nums[k] <= mid
                // nums[j] <= mid / nums[i];
                //            floor(2.8)
                //          <= 2
                // 找出第一個 > 2 那他之前都可以
                if (fixed > 0) {
                    // 2
                    ll target = floor(mid * 1.0 / fixed);
                    auto it = upper_bound(nums2.begin(), nums2.end(), target);
                    total += it - nums2.begin();
                } else if (fixed == 0) {
                    // if mid > 0, then 0 * anything will be <= mid
                    if (mid > 0) {
                        total += nums2.size();
                    } else {
                        total += 0;
                    }
                } else if (fixed < 0) {
                    // nums[j] >= mid / nums[i];
                    //     >= 2.8
                    //   >= 3
                    // 找出第一個 >=3
                    ll target = ceil(mid * 1.0 / fixed);
                    auto it = lower_bound(nums2.begin(), nums2.end(), target);
                    // 1 2 3 5
                    total += nums2.end() - it;
                }
            }
            return total >= k;
        };

        // log n => so i can have an isOK thats is nlogn
        while (start < end) {
            ll mid = start + (end - start) /2;
            // if the current # is the kth smallest
            // if there are too few products that are less than mid => returns false
            if (isOK(mid)) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2, 5};
    vector<int> nums2 = {3, 4};
    int k = 2;
    long long res = s.kthSmallestProduct(nums1, nums2, k);
    cout << (res == 8 ? "true" : ("false " + to_string(res))) << endl;

    nums1 = {-2, -1, 0, 1, 2};
    nums2 = {-3, -1, 2, 4, 5};
    k = 3;
    res = s.kthSmallestProduct(nums1, nums2, k);
    cout << (res == -6 ? "true" : ("false " + to_string(res))) << endl;
}
