#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int> &nums, int n) : n(n), tree(4 * n)
    {
        build(0, nums, 0, n - 1);
    }
    void build(int node, vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            tree[node] = nums[l];
            return;
        }
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int mid = l + (r - l) / 2;
        build(left, nums, l, mid);
        build(right, nums, mid + 1, r);
        tree[node] = max(tree[left], tree[right]);
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
        {
            return INT_MIN;
        }
        if (ql <= l && r <= qr)
        {
            return tree[node];
        }

        int mid = l + (r - l) / 2;
        int left = query(node * 2 + 1, l, mid, ql, qr);
        int right = query(node * 2 + 2, mid + 1, r, ql, qr);
        return max(left, right);
    }
    void update(int node, int l, int r, int idx, int val)
    {
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (mid >= idx)
        {
            update(node * 2 + 1, l, mid, idx, val);
        }
        else
        {
            update(node * 2 + 2, mid + 1, r, idx, val);
        }
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();
        SegmentTree st = SegmentTree(baskets, baskets.size());
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int current_fruit = fruits[i];
            int start = 0;
            int end = n - 1;

            while (start < end)
            {
                int mid = start + (end - start) / 2;
                if (st.query(0, 0, n - 1, start, mid) >= current_fruit)
                {
                    end = mid;
                }
                else
                {
                    start = mid + 1;
                }
                // } else {
                //     break;
                // }
            }
            if (st.query(0, 0, n - 1, start, start) >= current_fruit)
            {
                st.update(0, 0, n - 1, start, INT_MIN / 2);
            }
            else
            {
                res++;
            }
        }

        return res;
    }
};
