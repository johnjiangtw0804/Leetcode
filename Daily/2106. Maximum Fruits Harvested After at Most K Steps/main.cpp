#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        // maxSubArray but when start and end
        // when left by 0 -> k right by k - left
        // and do the same for right
        // we need to scan the range as big as possible
        // 這題重點我覺得是先走左邊再走右邊結果不同，可以用代數字的方式證明
        // 再來，start position要先放入去做擋版，確保 lowerbound prev(upperbound) 不會找不到
        int n = fruits.size();
        vector<int> positions;
        positions.push_back(-1);
        vector<int> counts;
        bool notSeen = true;
        counts.push_back(0);
        int startPosIndx = -1;
        int prefix = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = fruits[i][0];
            int count = fruits[i][1];
            if (pos > startPos && notSeen)
            {
                positions.push_back(startPos);
                counts.push_back(prefix);
                notSeen = false;
                startPosIndx = positions.size() - 1;
            }
            positions.push_back(pos);
            counts.push_back(count + prefix);
            prefix += count;
        }
        if (notSeen)
        {
            positions.push_back(startPos);
            counts.push_back(prefix);
            startPosIndx = positions.size() - 1;
        }

        int res = INT_MIN / 2;
        for (int leftStep = 0; leftStep <= k; leftStep++)
        {
            auto it = lower_bound(positions.begin() + 1, positions.begin() + startPosIndx, startPos - leftStep);
            int leftIdx = (it - positions.begin());
            int leftStop = *it;
            int stepsLeft = k - (startPos - leftStop);
            it = prev(upper_bound(positions.begin() + 1, positions.end(), leftStop + stepsLeft));
            int rightIdx = it - positions.begin();
            int totalFruits = counts[rightIdx] - counts[leftIdx - 1];
            res = max(totalFruits, res);
        }
        // 先走右再走左
        for (int rightStep = 0; rightStep <= k; rightStep++)
        {
            auto it = prev(upper_bound(positions.begin() + startPosIndx, positions.end(), startPos + rightStep));
            int rightIdx = (it - positions.begin());
            int rightStop = *it;
            int stepsLeft = k - (rightStop - startPos);
            it = lower_bound(positions.begin() + 1, positions.end(), rightStop - stepsLeft);
            int leftIdx = it - positions.begin();
            int totalFruits = counts[rightIdx] - counts[leftIdx - 1];
            res = max(totalFruits, res);
        }

        return res;
    }
};
