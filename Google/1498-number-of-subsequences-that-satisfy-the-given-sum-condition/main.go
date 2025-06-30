package main

import (
	"sort"
)

func numSubseq(nums []int, target int) int {
	mod := (int)(1e9 + 7)
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	// fixed an i => look for j
	// [3] -> Min value + max value <= target (3 + 3 <= 9)
	power := make([]int, len(nums)+1)
	power[0] = 1
	for i := 1; i <= len(nums); i++ {
		power[i] = power[i-1] * 2 % mod
	}

	res := 0
	for i, _ := range nums {
		// we can do two pointers here but i may try bst
		start := i
		end := len(nums) - 1
		// target = 3 than anything  <= target works
		// (.... target) ... j
		upperBoundVal := target - nums[i]
		// 找出來了 [....xxx] 如果 > 靠左
		// <= 靠右
		for start < end {
			mid := start + (end-start)/2
			if nums[mid] > upperBoundVal {
				end = mid
			} else {
				start = mid + 1
			}
		}
		j := start
		// cant find within this range => everything is <=
		if nums[start] <= upperBoundVal {
			res = (res + power[j-i]) % mod
			// we found
		} else {
			// nothing in between
			if j == i {
				continue
			} else {
				res = (res + power[j-1-i]) % mod
			}
		}
	}
	return int(res)
}
