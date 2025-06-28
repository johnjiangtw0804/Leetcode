# 2099. Find Subsequence of Length K With the Largest Sum (Go 筆記)

## 📌 題目重點

- 從 `nums` 找出長度為 `k` 的子序列 (subsequence)
- 使其總和最大
- 必須保留原相對順序

---

## 🗂️ Go 語法小抄

### ✅ `sort.Slice` 才能使用自定義 comparator

```go
sort.Slice(slice, func(i, j int) bool {
    return slice[i].val > slice[j].val // 例如: 依值降序
})
```

⚠️ 注意: slices.Sort 只能對內建可比較型別 ([]int、[]string) 排序，不能用自定義 comparator。

✅ 切片切割規則

```go
sub := arr[0:n] // 左閉右開，含 0 不含 n
```


```go
s := make([]int, 0)           // 空切片
m := make(map[string]int)     // 空 map
```

🧩 常見比較邏輯
依值由大到小

```go
sort.Slice(pairs, func(i, j int) bool {
    return pairs[i].val > pairs[j].val
})
```

依 index 由小到大 (還原原本順序)

```go
sort.Slice(pairs, func(i, j int) bool {
    return pairs[i].idx < pairs[j].idx
})
```
