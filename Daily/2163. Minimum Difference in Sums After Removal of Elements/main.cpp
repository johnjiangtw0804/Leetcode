#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        ll n = nums.size() / 3;
        priority_queue<ll, vector<ll>, less<ll>> pq;

        // some are impossible
        vector<ll> pre_min_sum_with_n_elements(nums.size(), -1);
        ll current_sum = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            ll num = nums[i];
            pq.push(num);
            current_sum += num;
            if (pq.size() <= n)
            {
                if (pq.size() == n)
                    pre_min_sum_with_n_elements[i] = current_sum;
                continue;
            }
            current_sum -= pq.top();
            pq.pop();
            pre_min_sum_with_n_elements[i] = current_sum;
        }
        priority_queue<ll, vector<ll>, greater<ll>> pq_max;
        vector<ll> post_max_sum_with_n_elements(nums.size(), -1);
        current_sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ll num = nums[i];
            current_sum += num;
            pq_max.push(num);
            if (pq_max.size() <= n)
            {
                if (pq_max.size() == n)
                    post_max_sum_with_n_elements[i] = current_sum;
                continue;
            }
            current_sum -= pq_max.top();
            pq_max.pop();
            post_max_sum_with_n_elements[i] = current_sum;
        }
        ll res = LONG_MAX;
        for (int i = 0; i < (int)pre_min_sum_with_n_elements.size() - 1; i++)
        {
            if (pre_min_sum_with_n_elements[i] != -1 && post_max_sum_with_n_elements[i + 1] != -1)
            {
                res = min(pre_min_sum_with_n_elements[i] - post_max_sum_with_n_elements[i + 1], res);
            }
        }
        return res;
    }
};
