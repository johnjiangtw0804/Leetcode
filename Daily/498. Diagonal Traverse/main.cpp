#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    int m;
    int n;
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        m = mat.size();
        n = mat[0].size();
        deque<vector<int>> q;
        q.push_front({mat[0][0], 0, 0});
        vector<int> res;
        res.push_back(mat[0][0]);
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        seen[0][0] = true;
        bool flag = true;
        while (q.size() > 0)
        {
            int lvl = q.size();
            vector<vector<int>> temp;
            for (int l = 0; l < lvl; l++)
            {
                // val, i, j
                vector<int> curr;
                curr = q.front();
                q.pop_front();
                int i = curr[1];
                int j = curr[2];
                int right = rightChild(i, j, mat);
                if (right != INT_MIN && !seen[i][j + 1])
                {
                    temp.push_back({right, i, j + 1});
                    q.push_back(temp[temp.size() - 1]);
                    seen[i][j + 1] = true;
                }
                int left = leftChild(i, j, mat);
                if (left != INT_MIN && !seen[i + 1][j])
                {
                    temp.push_back({left, i + 1, j});
                    q.push_back(temp[temp.size() - 1]);
                    seen[i + 1][j] = true;
                }
            }

            if (flag)
            {
                for (int i = 0; i < temp.size(); i++)
                {
                    res.push_back(temp[i][0]);
                }
            }
            else
            {
                for (int i = temp.size() - 1; i >= 0; i--)
                {
                    res.push_back(temp[i][0]);
                }
            }
            flag ^= true;
        }
        return res;
    }
    int leftChild(int i, int j, vector<vector<int>> &mat)
    {
        if (i + 1 >= m)
        {
            return INT_MIN;
        }
        return mat[i + 1][j];
    }
    int rightChild(int i, int j, vector<vector<int>> &mat)
    {
        if (j + 1 >= n)
        {
            return INT_MIN;
        }
        return mat[i][j + 1];
    }
};
