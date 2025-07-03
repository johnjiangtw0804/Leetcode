#include <vector>
#include <iostream>


using namespace std;
using ll = long long;
class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        long long res = 0;
        for (int i = 0; i <= limit; i++)
        {
            // dont take too much
            if (i > n)
            {
                break;
            }
            // dont take too little
            if ((limit * 2 + i) < n)
            {
                continue;
            }
            int candiesLeft = n - i;

            int maxCanTake = min(limit, candiesLeft);
            int minCanTake = max(0, (candiesLeft - limit));
            res += (maxCanTake - minCanTake) + 1;
        }
        return res;
    }
};
