#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
using PII = pair<int, int>;

class Solution
{
private:
    int m, n;
    set<PII> find(vector<vector<int>> &board)
    {
        // horizontal ->
        set<PII> crushedSet;
        for (int r = 0; r < m; r++)
        {
            for (int c = 1; c < n - 1; c++)
            {
                if (board[r][c] == 0)
                {
                    continue;
                }
                if ((board[r][c - 1] == board[r][c]) && (board[r][c] == board[r][c + 1]))
                {
                    crushedSet.insert(PII(r, c - 1));
                    crushedSet.insert(PII(r, c));
                    crushedSet.insert(PII(r, c + 1));
                }
            }
        }

        // vertical
        for (int c = 0; c < n; c++)
        {
            for (int r = 1; r < m - 1; r++)
            {
                if (board[r][c] == 0)
                {
                    continue;
                }
                if ((board[r - 1][c] == board[r][c]) && (board[r][c] == board[r + 1][c]))
                {
                    crushedSet.insert(PII(r - 1, c));
                    crushedSet.insert(PII(r, c));
                    crushedSet.insert(PII(r + 1, c));
                }
            }
        }
        return crushedSet;
    }
    void crush(const set<PII> &crushedSet, vector<vector<int>> &board)
    {
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (crushedSet.find(PII(r, c)) != crushedSet.end())
                {
                    board[r][c] = 0;
                }
            }
        }
    }
    void drop(vector<vector<int>> &board)
    {
        for (int c = 0; c < n; c++)
        {
            int writeRow = m - 1;
            for (int r = m - 1; r >= 0; r--)
            {
                if (board[r][c] != 0)
                {
                    swap(board[writeRow][c], board[r][c]);
                    writeRow--;
                }
            }
        }
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        this->m = board.size();
        this->n = board[0].size();
        set<PII> crushedSet;
        bool gameInit = true;
        while (crushedSet.size() > 0 || gameInit)
        {
            crushedSet = find(board);
            crush(crushedSet, board);
            drop(board);
            gameInit = false;
        }
        return board;
    }
};

int main() {
    return 0;
}
