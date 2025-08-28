#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        // 00 11 22
        // 01 12
        int m = grid.size();
        int n = grid[0].size();
        // ascending
        for (int j = 1; j < n; j++)
        {
            vector<int> asc;
            int i = 0, c = j;
            while (c < n && i < m)
            {
                asc.push_back(grid[i][c]);
                i++;
                c++;
            }
            sort(asc.begin(), asc.end());
            i = 0;
            c = j;
            while (c < n && i < m)
            {
                grid[i][c] = asc[i];
                i++;
                c++;
            }
        }

        // descending
        for (int i = 0; i < m; i++)
        {
            vector<int> desc;
            int r = i, c = 0;
            while (c < n && r < m)
            {
                desc.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(desc.begin(), desc.end(), std::greater<int>());
            r = i, c = 0;
            while (c < n && r < m)
            {
                grid[r][c] = desc[c];
                r++;
                c++;
            }
        }

        return grid;
    }
};
