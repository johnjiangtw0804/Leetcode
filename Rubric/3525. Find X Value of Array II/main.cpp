#include <vector>
#include <iostream>
using namespace std;

// every query we need to find [start....] with some removed suffix => to get remainder == xi
// query[l,r] => returns count(all the prefix products % k)
struct Node
{
    int prod;
    vector<int> remain;
    Node()
    {
        prod = 1;
        remain = vector<int>(5, 0);
    }
};

class SegmentTree
{
private:
    int n;
    int k;
    vector<Node> tree;
    void merge(int node)
    {
        Node &left = tree[2 * node + 1];
        Node &right = tree[2 * node + 2];

        tree[node].prod = (left.prod * right.prod) % k;
        for (int i = 0; i < k; i++)
        {
            tree[node].remain[i] = left.remain[i];
        }
        // with something at your right which is product right
        for (int i = 0; i < k; i++)
        {
            //    [0 1 0 0 ]
            //  left Prod = 3
            //  total :[1 * 3 % k] + 1
            // 原本右邊的 i * product 被貢獻到左邊
            tree[node].remain[(left.prod * i) % k] += (right.remain[i]);
        }
    }

    void build(const vector<int> &nums, int left, int right, int node)
    {
        // 葉節點的 setup
        if (left == right)
        {
            tree[node].prod = nums[left];
            tree[node].remain[nums[left] % k] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        build(nums, left, mid, 2 * node + 1);
        build(nums, mid + 1, right, 2 * node + 2);
        merge(node);
    }

public:
    SegmentTree(const vector<int> &arr, int k)
    {
        this->n = arr.size();
        this->k = k;
        tree.resize(4 * n);
        build(arr, 0, n - 1, 0);
    }

    void update(int left, int right, int key, int val, int node)
    {
        if (left == right)
        {
            for (int i = 0; i < k; i++)
            {
                tree[node].remain[i] = 0;
            }
            tree[node].remain[val % k] = 1;
            tree[node].prod = val % k;
            return;
        }
        // 1 2 3
        int mid = left + (right - left) / 2;
        if (key <= mid)
        {
            update(left, mid, key, val, 2 * node + 1);
        }
        else
        {
            update(mid + 1, right, key, val, 2 * node + 2);
        }
        merge(node);
    }

    Node query(int left, int right, int ql, int qr, int node)
    {
        if (qr < left || ql > right)
        {
            return Node();
        }
        if (ql <= left && right <= qr)
        {
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        Node leftRes = query(left, mid, ql, qr, 2 * node + 1);
        Node rightRes = query(mid + 1, right, ql, qr, 2 * node + 2);
        int leftProd = leftRes.prod;
        for (int i = 0; i < k; i++)
        {
            leftRes.remain[(leftProd * i) % k] += rightRes.remain[i];
        }
        leftRes.prod = (leftRes.prod * rightRes.prod) % k;
        return leftRes;
    }
};

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums, int k, vector<vector<int>> &queries)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] % k;
        }
        SegmentTree sm(nums, k);
        vector<int> res;
        for (const vector<int> &q : queries)
        {
            int idx = q[0];
            int val = q[1] % k;
            int start = q[2];
            int x = q[3] % k;
            sm.update(0, n - 1, idx, val, 0);
            res.push_back(sm.query(0, n - 1, start, n - 1, 0).remain[x]);
        }
        return res;
    }
};

// build() 建構樹 初始化時，把原陣列分段算好 prod 與 prefix remain
// merge() 合併兩個子樹 把左右子段合併成父節點的 prod 與 prefix remain
// update() 單點更新 改變某個 index 的值，然後沿著路徑重新合併父節點
// query() 區間查詢 查詢[L, R] 的 prod 與 prefix remain 統計，合併多段結果
int main()
{
    vector<int> nums = {2, 3, 5};
    int k = 4;

    for (int &x : nums)
        x %= k;

    SegmentTree st(nums, k);

    cout << "Initial prefix remain count for remainder=1 in [0,2]: "
         << st.query(0, nums.size() - 1, 0, 2, 0).remain[1] << endl;

    cout << "Update nums[1] = 2" << endl;
    st.update(0, nums.size() - 1, 1, 2 % k, 0);

    cout << "After update, prefix remain count for remainder=1 in [0,2]: "
         << st.query(0, nums.size() - 1, 0, 2, 0).remain[1] << endl;

    return 0;
}
