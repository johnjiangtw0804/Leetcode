# 3574. Maximize Subarray GCD Score

**Difficulty**: Hard
**Link**: [LeetCode 3574](https://leetcode.com/problems/maximize-subarray-gcd-score/)

---

## ❓ Problem Summary

You are given an integer array `nums` and an integer `k`.
You may **double any `k` elements within a contiguous subarray**, and then compute:
score = subarray_length × GCD(after_k_doubles)

Return the **maximum possible score**.

---

## 🧠 Hint

你會發現 (xxxx) 是你要 double 的， (....) 是你不要 double 的
(xxxx) 這組有共同的最低質因數（lowest prime factor）
這組的 GCD 如果 k 夠，可以被提升 (*2)，關鍵是 (xxxx) 有幾個？
怎麼找出 (xxxx)？lowest prime 是 2，所以我們先看 power of 2 最小的那些數，這些數字的數量代表了 (xxxx)
如果 power of 2 最小的數在這個 subarray 中個數 <= k，就能全部 double，把 GCD *2
如果超過 k，就不能全部升級，那麼 GCD 就不能變了
要怎麼算 power of 2？你可以不斷除以 2，或是用 __builtin_ctz()
記得只有最低 power of 2 才是 bottleneck，多出來的數 double 也沒意義
