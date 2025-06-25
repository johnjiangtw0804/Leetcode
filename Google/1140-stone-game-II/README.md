# 1140. Stone Game II

## 🧠 Problem Summary

Alice and Bob take turns removing piles of stones from a row.
In each turn, a player may take `x` piles where `1 <= x <= 2M`.

- `M` starts as `1` and becomes `max(M, x)` after each turn.
- The game ends when there are no more piles.
- Alice starts first and tries to collect the most stones.

❓ Return the **maximum number of stones Alice can get** if both play optimally.

---

## 🎯 Core Insight

At each step:

> Alice wants to **maximize**:
> `current scores taken + (剩下的總分 - Bob’s optimal response)`

Which simplifies to:

```cpp
res = max(res, suffix[i] - helper(i + x, max(M, x)))
