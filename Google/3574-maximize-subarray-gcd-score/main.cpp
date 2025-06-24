#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
class Solution
{
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    long long maxGCDScore(vector<int> &nums, int k)
    {
        // 你會發現 (xxxx) 是你要 double 的， (....) 是你不要 double的
        // (xxxx) has common lowest prime factors
        // common gcd in (xxxx) 能 * 2，如果 k 夠。 也就是說 gcd 中 (xxxx) 有幾個？
        // 那我們怎麽找出 (XXXX)， lowest prime 是 2，先看 common 2 power 有幾個 有多的在看別的
        // 那這邊我們就發現 lowest common 2 power 得放成 (xxxx) 組成這個組
        // how to calculate the power of 2s
        // 你可以一直除或者用 builtint_ctz()
        // 把 lowest common power of 2s 統計一下如果這個 subarray |lowest common power of 2s| <= k 我們 gcd 可以 * 2，但不能多了，因為其他 * 2 總體不會變大，除非每個數能放大很多次
        int n = nums.size();
        vector<int> powerofTwo(n, 0);
        for (int i = 0; i < n; i++)
        {
            // powerofTwo[i] = __builtin_ctz(nums[i]); // or res = x & -x then log(res)
            int res = nums[i] & -nums[i];
            powerofTwo[i] = log2(res);
        }
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            int minCount = 0;
            int minPowerOfTwo = INT_MAX;
            int tempGCD = 0;
            for (int j = i; j < n; j++)
            {
                tempGCD = gcd(tempGCD, nums[j]);
                if (minPowerOfTwo > powerofTwo[j])
                {
                    minPowerOfTwo = powerofTwo[j];
                    minCount = 1;
                }
                else if (minPowerOfTwo == powerofTwo[j])
                {
                    minCount++;
                }
                if (minCount <= k)
                {
                    res = max(res, (j - i + 1) * 1ll * tempGCD * 2ll);
                }
                else
                {
                    res = max(res, (j - i + 1) * 1ll * tempGCD);
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input1 =  {3, 5, 7};
   ll res = s.maxGCDScore(input1, 2);
   cout << ((res == 14) ? "true" : ("false " + to_string(res))) << endl;
}
