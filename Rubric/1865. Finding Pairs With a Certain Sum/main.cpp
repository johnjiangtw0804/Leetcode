#include <iostream>
#include <vector>

using namespace std;

class FindSumPairs
{
private:
    unordered_map<int, int> freq;
    vector<int> nums2;
    vector<int> nums1;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int n2 : nums2)
        {
            freq[n2]++;
        }
    }

    void add(int index, int val)
    {
        if (val == 0)
        {
            return;
        }
        freq[nums2[index]]--;
        freq[nums2[index] + val]++;
        nums2[index] += val;
    }

    int count(int tot)
    {
        int res = 0;
        for (int n1 : nums1)
        {
            if (freq.find(tot - n1) != freq.end())
            {
                res += freq[tot - n1];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
