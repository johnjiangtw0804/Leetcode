package main

import (
	"sort"
)

func maxSubsequence(nums []int, k int) []int {
	type pair struct {
		val int
		idx int
	}

	pairSlice := make([]pair, 0)
	for idx, val := range nums {
		pairSlice = append(pairSlice, pair{val, idx})
	}
	sort.Slice(pairSlice, func(i, j int) bool {
		return pairSlice[i].val > pairSlice[j].val
	})

	pairSlice = pairSlice[:k]
	sort.Slice(pairSlice, func(i, j int) bool {
		return pairSlice[i].idx < pairSlice[j].idx
	})
	res := make([]int, 0)
	for _, p := range pairSlice {
		res = append(res, p.val)
	}
	return res
}
