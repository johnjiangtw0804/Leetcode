# 853. Car Fleet

**Difficulty**: Medium
**Link**: https://leetcode.com/problems/car-fleet/

---

## ❓ Problem Summary

N cars are going to the same destination `target`. Each car has a `position[i]` and a `speed[i]`. A **car fleet** is formed when a car catches up to another and they travel together at the slower car’s speed.

Return the number of **distinct car fleets** that will arrive at the destination.

---

## 🧠 Solution Overview

### Approach

1. For each car, calculate its **time to reach the target** using:

   \[
   \text{time} = \frac{\text{target} - \text{position}}{\text{speed}}
   \]

2. Sort cars by position in **descending** order (from furthest from target to closest).
3. Use a stack to keep track of fleet formation:
   - If a car takes **more time** than the previous, it starts a new fleet.
   - If it takes **less or equal** time, it merges with the current fleet.

---

## ⚠️ Note

> Be very careful with integer division!  
> Always **cast to `double`** when computing time-to-target.  
> This is a common source of bugs in this problem.

```cpp
for (PII& pos2Speed : positionWithSpeed) {
    double step = (target - pos2Speed.first) / (1.0 * pos2Speed.second);
    stepsToTarget.push_back(step);
}
