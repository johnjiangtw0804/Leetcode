#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> prefix;
    Solution(vector<int> &w)
    {
        int sum = 0;
        for (int weight : w)
        {
            prefix.push_back(weight + sum);
            sum += weight;
        }
    }

    int pickIndex()
    {
        int num = (rand() % prefix.back()) + 1;
        int start = 0;
        int end = (int)prefix.size() - 1;
        // 2 2 3 5
        // find 4
        // lower_bound >= target
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (prefix[mid] < num)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
