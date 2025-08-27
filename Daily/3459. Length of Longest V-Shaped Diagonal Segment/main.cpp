#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int memo[502][502][4][2];
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(memo, 0 ,sizeof(memo));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(i, j, 0, true, grid));
                    res = max(res, dfs(i, j, 1, true, grid));
                    res = max(res, dfs(i, j, 2, true, grid));
                    res = max(res, dfs(i, j, 3, true, grid));
                }
            }
        }
        return res;
    }

    bool isOK(vector<vector<int>>& grid, int i, int j, int nextI, int nextJ) {
        if (grid[i][j] == 1 && grid[nextI][nextJ] == 2) return true;
        if (grid[i][j] == 2 && grid[nextI][nextJ] == 0) return true;
        if (grid[i][j] == 0 && grid[nextI][nextJ] == 2) return true;
        return false;
    }

    int dfs (int i, int j, int dir, int canTurn, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (memo[i][j][dir][canTurn] != 0) {
            return memo[i][j][dir][canTurn];
        }
        int nextI = i + directions[dir][0];
        int nextJ = j + directions[dir][1];

        int res = 1;
        if ((nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m) &&
            isOK(grid, i, j, nextI, nextJ)) {
            res = max(res, 1 + dfs(nextI, nextJ, dir, canTurn, grid));
        }
        if (canTurn) {
            int dir2 = (dir + 1) % 4;
            nextI = i + directions[dir][0];
            nextJ = j + directions[dir][1];
            if ((nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m) &&
                isOK(grid, i, j, nextI, nextJ)) {
                res = max(res, 1 + dfs(nextI, nextJ, dir2, !canTurn, grid));
            }
        }
        return memo[i][j][dir][canTurn] = res;
    };
};
