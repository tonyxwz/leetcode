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

