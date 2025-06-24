# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

**Difficulty**: Medium
**Link**: [LeetCode 1438](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

---

## ❓ Problem Summary

Given an integer array `nums` and an integer `limit`, return the length of the longest continuous subarray such that the **absolute difference between any two elements** is **less than or equal to `limit`**.

---

## 🧠 Core Idea

To solve this in **O(n)**, we use a **sliding window** approach combined with **two monotonic deques** to efficiently track:

- The current **maximum**
- The current **minimum**
- And importantly, the **next possible max/min candidates** as the window slides

We maintain the invariant:

```text
max(nums[i..j]) - min(nums[i..j]) <= limit
```

---

## ⚠️ Key Insight (Hard Part)

The tricky part isn't just maintaining the current min and max,
but also efficiently tracking the next valid min and max when the left edge of the window (slow) moves forward.

We avoid recomputing min and max from scratch by storing indices in two deques:

A monotonically decreasing deque to track the current maximum and its possible successors.
The front of the deque always holds the index of the current maximum in the window.
Any elements smaller than the current one are removed from the back, because they can no longer compete to be the max — they're dominated.

A monotonically increasing deque to track the current minimum and its possible successors.
The front of this deque always holds the index of the current minimum.
Elements greater than the current one are removed from the back for the same reason — they can’t beat the new element to be the future minimum.

This way, we always know the current min and max in constant time.
As the window slides, we remove elements from the front of either deque only if their indices fall outside the current window.

---

## 📈 Time and Space Complexity

⏱ Time Complexity: **O(n)**

Each element is pushed and popped from each deque at most once.

The sliding window moves left (slow++) only when necessary, but overall advances across the entire array once.

All operations inside the loop (push, pop, comparisons) are amortized constant time.

✅ Total time: O(n) where n is the size of nums.

🧠 Space Complexity: **O(n)**

In the worst case, all elements may remain in each deque (though typically less).

Therefore, each of the two deques may store up to n indices.

✅ Total space: O(n) for the two deques.
