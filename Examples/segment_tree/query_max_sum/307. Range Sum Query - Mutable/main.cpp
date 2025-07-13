#include <vector>
#include <iostream>

using namespace std;

class SegmentTree
{
private:
    vector<int> data;
    int n;
    void merge(int node)
    {
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        data[node] = data[leftChild] + data[rightChild];
    }

public:
    SegmentTree(vector<int> &nums, int n) :n(n), data(4*n)
    {
        // 裡面存的東西很重要，看你怎麼定義
        build(0, n - 1, 0, nums);
    }
    void build(int left, int right, int node, vector<int> &nums)
    {
        if (left == right)
        {
            data[node] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(left, mid, 2 * node + 1, nums);
        build(mid + 1, right, 2 * node + 2, nums);
        merge(node);
    }

    void update(int left, int right, int node, int index, int val)
    {
        // find the leaf node, and goes up to update the range
        if (left == right)
        {
            data[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (index <= mid)
        {
            update(left, mid, 2 * node + 1, index, val);
        }
        else
        {
            update(mid + 1, right, 2 * node + 2, index, val);
        }
        merge(node);
    }

    int query(int ql, int qr, int left, int right, int node) const
    {
        if (qr < left || ql > right)
        {
            return 0; // No overlap
        }
        if (ql <= left && right <= qr)
        {
            return data[node]; // // Fully covered
        }
        int mid = left + (right - left) / 2;
        int leftNode = query(ql, qr, left, mid, 2 * node + 1);
        int rightNode = query(ql, qr, mid + 1, right, 2 * node + 2);
        return leftNode + rightNode; // merge
    }
};

class NumArray
{
private:
    SegmentTree segmentTree;
    int n;

public:
    NumArray(vector<int> &nums) : segmentTree(nums, nums.size()), n(nums.size()){}

    void update(int index, int val)
    {
        segmentTree.update(0, n - 1, 0, index, val);
    }

    int sumRange(int left, int right) const
    {
        return segmentTree.query(left, right, 0, n - 1, 0);
    }
};
