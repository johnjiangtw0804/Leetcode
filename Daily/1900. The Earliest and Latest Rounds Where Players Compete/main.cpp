#include <vector>
using namespace std;

class Solution
{
public:
    int r_min = 6;
    int r_max = 1;
    vector<int> res;
    void f(int round, int l, int r, int n)
    {
        if (l > r)
        {
            return f(round, r, l, n);
        }
        if (l == r)
        {
            r_max = max(r_max, round);
            r_min = min(r_min, round);
            return;
        }
        int shouldLeft = (n + 1) / 2;
        int half = (n + 1) / 2;
        for (int i = 1; i <= l; i++)
        {
            if (r > half)
            {
                for (int j = half - i; j >= half - (n - l - r) - i; j--)
                {
                    f(round + 1, i, j, shouldLeft);
                }
            }
            else
            {
                for (int j = r - i; j >= (l - i) + 1; j--)
                {
                    f(round + 1, i, j, shouldLeft);
                }
            }
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        f(1, firstPlayer, n - secondPlayer + 1, n);
        return {r_min, r_max};
    }
};
