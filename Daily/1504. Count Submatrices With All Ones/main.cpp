#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // 我們要算 當前 ending at j col at i row 之 submatrices with all ones
        // prevSmaller 之前的都可以延伸過來
        // 然後prevSmaller 之後的也可被這邊卡斷
        // Counter[j] += Counter[prevSmaller] + (j - prevSmaller) * height[j]
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        vector<int> height(150, 0);
        for (int i = 0; i < m; i++) {
            vector<int> getPrevSmaller(150, -1);
            vector<int> Counter(150, 0);
            stack<int> Stack;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }
            for (int j = 0; j < n; j++) {
                int h = height[j];
                // increasing stack
                while (Stack.size() > 0 && height[Stack.top()] > h) {
                    Stack.pop();
                }
                // stack 的前一個就是我要的
                if (Stack.size() > 0) {
                    getPrevSmaller[j] = Stack.top();
                }
                Stack.push(j);
                Counter[j] += (getPrevSmaller[j] == -1 ? 0 : Counter[getPrevSmaller[j]]) +
                               (j - getPrevSmaller[j]) * height[j];
                // cout << Counter[j] << endl;
                res += Counter[j];
            }
        }
        return res;
    }
};
