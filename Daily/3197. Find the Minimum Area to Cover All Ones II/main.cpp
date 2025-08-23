#include <vector>

using namespace std;

class Solution {
private:
    int minSumWithinArea(vector<vector<int>>& grid, int l, int r, int u, int d) {
        int minR = grid.size();
        int maxR = 0;
        int minC = grid[0].size();
        int maxC = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    minR = min(minR, i);
                    minC = min(minC, j);
                    maxR = max(maxR, i);
                    maxC = max(maxC, j);
                }
            }
        }
        return minR <= maxR ? (maxR - minR + 1) * (maxC - minC + 1) : INT_MAX/4;
    }
    int solve(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = INT_MAX / 2;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n -1;j++) {
                res = min(res, (minSumWithinArea(grid, 0, n-1, 0, i) + 
                                minSumWithinArea(grid, 0, j, i+1, m-1) + 
                                minSumWithinArea(grid, j+1, n-1, i+1, m-1)));
            }
        }
        for (int i = m - 1; i >= 1; i--) {
            for (int j = 0; j < n - 1; j++) {
                res = min(res, (minSumWithinArea(grid, 0, j, 0, i-1) + 
                                minSumWithinArea(grid, j+1, n-1, 0, i-1) + 
                                minSumWithinArea(grid, 0, n-1, i, m-1)));
            }
        }

        for (int i = 0; i < m - 2; i ++) {
            for (int j = i + 1; j < m- 1; j++) {
                res = min(res, (minSumWithinArea(grid, 0, n-1, 0, i) + 
                        minSumWithinArea(grid, 0, n-1, i+1, j) + 
                        minSumWithinArea(grid, 0, n-1, j+1, m-1)));
            }
        }
        return res;
    }
    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int m = grid.size();    
        int n = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                res[n-1-j][i] = grid[i][j];
            }
        }
        return res;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        // rotate counter clockwise by 90 degrees
        // 3 non overlapping
        int oneCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    oneCount++;
                }
            }
        }
        if (oneCount == 0) {
            return 0;
        }
        vector<vector<int>> rotated_grid = rotate(grid);
        return min(solve(rotated_grid), solve(grid));
    }
};
