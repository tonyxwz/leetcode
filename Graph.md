# Graph Algorithms

## Topological sorting

Operation on directed acyclic graph (DAG)

- not unique

### Implementation

```c
#include <iostream>
```

## Bi-partition

Template problem, e.g. 785. Is Graph Bipartite.

### Solution

Graph coloring

- start from arbitrary node and mark it as red
- color its neighbors as opposite color (red <-> blue) recursively
- conflict ? good to go : not possible

## Union find

other names: 并查集, 不相交集, disjoint set...
Time complexity: `log*n` -> constant
这个算法的常数时间复杂度指的是平均而言，对于单个成员不一定如此。

### Equivalent relation 等价关系

- 自反性
- 对称性
- 传递性

### Dynamic equivalent relation problem (动态等价性问题)

Dynamic equivalent relation problems are sometimes implicit, therefore requires
computations before the relation can be discovered. We would like to be able to
make decisions instantly.

General disjoint set is initialized with size as argument. The disjoint set
initially contains a collection of `N` class, every element is regarded as
belonging to a class of itself (makes sense because we have not seen the dataset
yet). For each class `S_i` and `S_j` in the collection, the intersection of Si
and Sj is empty.

Two operations are defined on a disjoint set ADT.

1. find(element): returns the class in which element belongs.
2. union(e1, e2): establish the relation between e1 and e2.
    Union(e1, e2) -> class(e1) U class(e2). after this operation, the classes in
    the collection remains disjoint. Due to this reason, these work is also
    called the Find/Union algorithm on Disjoint set.

This algorithm is
1. dynamic: Union is changed on the fly
2. on-line (联机): the answer we have when it comes to a element and the answer
   we have after we processed all the input must be the same.

There're two schemes to solve dynamic equivalent problems.
1. find optimized
2. union optimized

### Optimization 优化方法

首先树和图有一个重要的指标：height, 决定时间复杂度。

1. path compression (路径压缩)
2. union by rank (按秩合并)

### Union Optimized

We don't require `find` operation to return some specific name for a certain
element, but require `find(a) == find(b)` if and only if `a` and `b` belong to
the same class.

因为我们调用 find api 的方式就是比较 find 对不同元素的返回值是否相同，如果相同
证明这两个元素是属于同一个类别。


### Pseudo-code
```python
class UnionFindSet:
    def __init__(self, n: size):
        self.parents = [1,..., n]
        self.ranks = [0,..., 0]

    def find(x: element):
        if x != self.parents[x]:
            self.parents[x] = self.find(self.parents[x])
        return parents[x]

    def union(x, y):
        px, py = find(x), find(y)
        if px == py:
            return false

        if self.rank[px] > self.rank[py]:
            self.parents[py] = px
        elif self.rank[px] < self.rank[py]:
            self.parents[px] = py
        else
            self.parents[py] = px
            self.rank[px]++
```
### Naive Implementation in C

`disjset.h`
```c
#pragma once
typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType s1, SetType s2);
SetType SetFind(DisjSet S, ElementType, x);
```

`disjset.c`
```c
#include "disjset.h"

void
Initialize(DisjSet S) {
    int i;
    for (i = NumSets; i > 0; i--)
        S[i] = 0;
}

void
SetUnion(DisjSet S, SetType root1, SetType root2) {
    S[root2] = root1;
}

SetType
SetFind(ElementType X, DisjSet S) {
    if (S[X] <= 0)
        return S[X];
    else
        return SetFind(S[X], S);
}
```

### Union by size

Instead of storing 0 in the root node, we store the opposite of the size of the
tree, e.g. -2 meaning that the tree has two nodes. When performing union
operation, always merge the smaller tree to the larger tree.

We need to initialize the DisjSet when -1.

Also possible: union by height - only increase the height when merging two trees
of the same height.

### Path compression (Optimization 2)

We create another array `rank` storing the upperbound of the height of subtrees
rooted at vertex `i` that will be used as *guiding heuristic* for UnionSet(i,j)
operation. After **path compression**, the rank could no longer reflect the
actual height of the the disjoint set any more.

`N`: the number of total items, each being a disjoint set of itself.
`p`: parents array, `p[i]` is the parent of item i
`rank`: rank array, `rank[i]` is the rank of item i

- Initialize:
    - `p[i] = i`
    - `rank[i] = 0`
    - O(N)
- FindSet: `FindSet(i)`, for vertex `i`, recursively goes up the tree. That is
  from `p[i]` recursively visit p[i] until we reach the root node (p[i] == i),
  the representative item of this disjoint set. **Path Compression Heuristic**
  is used in this implementation. Every node on the path from node `i` to its
  root are knows that root is their representative. O(1) for latter access. This
  is done by updating all the item during the back tracing.
- IsSameSet(i, j): test if `i` and `j` are in the same set (`FindSet(i) ==
  FindSet(j)`). O(2) -> O(1)
- UnionSet: `UnionSet(i, j)` if `i` and `j` are from two different disjoint
  sets, then the represetative item of the smaller set is changed to be the the
  child of the the larger (taller) set. Otherwise do nothing (already in the
  same set).

*union-by-rank* heuristic causes the trees to be relatively flatter. Only if the
trees are of the same height before merge, the resulted tree's rank will be
incremented by 1.

Rank is not the actual height of the trees (more like complexity of the trees
(huahua)).  Each time path compression is performed, at least one rank is wrong
(not reflecting the actual height of the tree). We don't need to fix this
because the rank is only to guide the merge of the trees.


### Reference

- https://algorithms.tutorialhorizon.com/disjoint-set-union-find-algorithm-union-by-rank-and-path-compression
- https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
- https://visualgo.net/en/ufds
- [visualgo](https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/unionfind_ds.py)
