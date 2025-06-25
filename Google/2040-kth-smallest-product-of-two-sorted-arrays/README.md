# LeetCode 2040 - Kth Smallest Product of Two Sorted Arrays

## 🚀 Problem Description

Given two **sorted arrays** `nums1` and `nums2`, return the **k-th smallest product** that can be formed by multiplying an element from `nums1` with an element from `nums2`.

- `nums1.length, nums2.length <= 5 * 10^4`
- `nums1` and `nums2` can contain **negative, zero, or positive** integers.

---

## 🧠 Approach

We cannot afford to compute all `O(n^2)` products directly.

### ✅ Strategy: **Binary Search on Product Values**

1. **Define search range**: product values range from `-1e10` to `1e10`.
2. Use a helper function `isOK(mid)` to **count how many products ≤ mid**.
3. Perform binary search: the first `mid` where the count ≥ `k` is our answer.

### ✅ Key Optimization

- Because both arrays are **sorted**, we can:
  - Use `upper_bound` when `nums1[i] > 0`
  - Use `lower_bound` when `nums1[i] < 0`
  - For `nums1[i] == 0`, count all of `nums2` if `mid >= 0`

---

## 🔧 Time Complexity

- Binary search over range: `O(log(maxProduct)) ≈ 64`
- For each `mid`, we scan `nums1` with `O(log n2)` per element
- **Overall: `O(n1 * log n2 * log maxProduct)`**

---

## 📂 File

```bash
2040-kth-smallest-product.cpp
