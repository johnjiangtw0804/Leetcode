#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res = vector<vector<int>>(numRows, vector<int>());
        int row = 0;
        while (row < numRows)
        {
            res[row] = vector<int>(row + 1);
            int start = 0;
            int end = row;
            res[row][start] = 1;
            res[row][end] = 1;
            for (int i = 1; i < end; i++)
            {
                res[row][i] = res[row - 1][i - 1] + res[row - 1][i];
            }
            row++;
        }
        return res;
    }
};
