# 一些总结

## 二分搜索的模板

```python
def binarySearch(list, target):
  l = 0
  r = len(list)
  while(l < r):
    m = l + (r-l)/2
    if condition:
      r = m
    else
      l = m + 1
  return l
```
在这里condition需要自己来确定，二叉搜索的意义是返回最小的满足
condition的下标。如查找lower bound的时候condition就是
`list[m] <= target`，在查找upper bound的时候condition就是
`list[m] < target`.

使用左闭右开的区间的好处是在最后返回的时候l和r是相同的，返回任意一个
都行，无需考虑。

查找 排序等问题经常需要跟踪数组的下标
有一些小技巧
- 保持数组头和数组off-edge的位置
- 循环的边界条件是l < r
- 求数组中间位置的时候，m = l + (r - l) / 2
  - 这样m就保证不会越界（如果l没有越界的话）