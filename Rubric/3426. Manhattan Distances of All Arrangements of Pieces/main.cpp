#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class Solution
{
private:
    int mod = 1e9 + 7;
    int quickPower(ll base, ll exp)
    {
        ll res = 1ll;
        ll multiply = base;
        // (base^power) * base^power base^power+1
        while (exp > 0)
        {
            int lastDigit = exp & 1;
            if (lastDigit == 1)
            {
                res = (res % mod * multiply % mod) % mod;
            }
            multiply = (multiply % mod * multiply % mod) % mod;
            exp /= 2;
        }
        return res % mod;
    }

public:
    int distanceSum(int m, int n, int k)
    {
        // You just need to know: for each possible distance between rows or columns,
        // how many pairs contribute that distance, ＝> 多少個點產生了這個距離
        // how many possible ways of placing two points on the grid
        // (d) * n * n d ranging from 1 to m -1 for points
        // row: (d) * (m-d: # of possible rows with d) * m * m => with d how many additional vals
        // col: (d) * (n-d: # of possible cols with d) * n * n ...
        // but this is when we only place two points
        // 我們總共會有多少種情況去 place these two points
        // when C (M*N-2) (k-2)
        // 簡單來說，每個 |d| 可以被產生幾次
        // 把所有 |d| 可產生的數字加起來就對了
        ll row = 0;
        for (ll d = 1ll; d < m; d++)
        {
            row = (row + ((((d) % mod * (m - d)) % mod * n) % mod * n) % mod) % mod;
        }
        ll col = 0;
        ll A = (m * n - 2);
        ll B = (k - 2);
        // A * A-1 * .. A-B+1
        // / B!
        ll denom = 1ll;
        for (ll i = 1; i <= B; i++)
        {
            denom = denom * (i) % mod; // 1 * 2 * 3...B
        }
        ll numer = 1ll;
        for (ll i = 0; i <= B - 1; i++)
        {
            numer = numer * (A - i) % mod; // A * ... A -(B-1)
        }

        ll base = (numer * quickPower(denom, mod - 2)) % mod;
        for (ll d = 1; d < n; d++)
        {
            col = (col + ((((d) * (n - d)) % mod * m) % mod * m) % mod) % mod;
        }
        return (((row + col) % mod) * base) % mod;
    }
};
