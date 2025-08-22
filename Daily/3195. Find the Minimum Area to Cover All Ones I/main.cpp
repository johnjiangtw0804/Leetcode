class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int firstRow = INT_MAX;
        int lastRow = INT_MIN;
        int firstCol = INT_MAX;
        int lastCol = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    firstRow = min(firstRow, i);
                    firstCol = min(firstCol, j);
                    lastRow = max(lastRow, i);
                    lastCol = max(lastCol, j);
                }
            }
        }
        if (firstRow == INT_MAX)
        {
            return 0;
        }

        return (lastRow - firstRow + 1) * (lastCol - firstCol + 1);
    }
};
