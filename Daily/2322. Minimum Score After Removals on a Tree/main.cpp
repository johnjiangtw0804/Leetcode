#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        // 要怎麼切? 找 edge
        // find one and then either side keep as a whole
        // and try to find c
        int total = 0;
        for (int num : nums)
        {
            total ^= num;
        }
        unordered_map<int, unordered_set<int>> adj;
        for (vector<int> edge : edges)
        {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        int res = INT_MAX;
        for (const vector<int> &edge : edges)
        {
            // break the edge
            int A = getAll(edge[0], adj, edge[1], nums);
            int B = total ^ A;
            // chop one from A
            dfs(edge[0], A, B, adj, res, edge[1], nums);
            dfs(edge[1], B, A, adj, res, edge[0], nums);
        }
        return res;
    }
    // chop some edges in A. using DFS post order
    int dfs(int node, int A, int B, unordered_map<int, unordered_set<int>> &adj,
            int &res, int prev, vector<int> &nums)
    {
        int total = 0;
        for (int next : adj[node])
        {
            if (next == prev)
            {
                continue;
            }

            // some subtree's XOR sum
            int C = dfs(next, A, B, adj, res, node, nums);
            int newA = A ^ C;
            int max_score = max(max(newA, C), B);
            int min_score = min(min(newA, C), B);
            res = min(res, max_score - min_score);
            total ^= C;
        }
        return total ^ nums[node];
    }

    int getAll(int node, unordered_map<int, unordered_set<int>> &adj, int prev, vector<int> &nums)
    {
        int val = nums[node];
        for (int next : adj[node])
        {
            if (next == prev)
            {
                continue;
            }
            val ^= getAll(next, adj, node, nums);
        }
        return val;
    }
};
