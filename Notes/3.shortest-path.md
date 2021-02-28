# Shortest path algorithms

## Single source shortest path algorithm

### 1. Dijkstra's algorithm (Greedy)
Time complexity ~ `O((E+V) * Log(V))`

non-negative edges only: this ensures that once a node is visited, it won't be further improved.

**How to remember**: dijkstra = BFS + priority queue. Just replace the queue in BFS with a priority queue, you get an outline of the dijkstra algorithm.

There're various ways to optimize the dijkstra's algorithm.
- using indexed priority queue so that you won't have deprecated nodes
- stop early if the node being queried is visited (won't be optimized further)

Steps:
0. dist: array(N, 0);
   q: priority queue (distance, node);
   visited: array(bool);
   prev: array(node);
1. q.push((0, start node)); dist[start node] = 0
2. while q is not empty, do
    `d, node = q.pop()`
    mark `node` as visited
    for each neighbour `u` of `node`, do
      relax `u`
    endfor
   endwhile
3. array dist is now the shortest path from source to every node in the graph. You could stop earlier if you only want the distance of one node.

There's a difference between selection and relaxation, which can be confusing. When a node is selected, it is optimized. Due to the non-negativity of the edges, you won't be able to select or relax a previously selected node.

**Relaxation**: once a new node is selected, update its neighbours' distances

```cpp
if (dist[u]+ uv < dist[v])
  dist[v] = dist[u] + uv;
```

This just calculates the shortest distance. In order to know the actual path, we need to keep track of the previous node.

### 2. Bellman-Ford algorithm (Dynamic Programming)
Time complexity ~ `O(EV)` -- worse than dijkstra

why use it? dijkstra fails due to there's negative weights.
Can detect negative cycle (leading to negative infinity of all downstream nodes)

**How to remember**: relax the distances `V-1` times

```pseudo
E : number of edges
V : number of vertices
S : source node
D : array of size V

D_0[S] = 0
D_0[others] = +infinity (INT_MAX)

# Relax V-1 times
for (i = 0; i < V - 1; ++i)
  D_{i+1} = copy(D_i);
  foreach edge in graph:
    if (D_i[edge.from] != INT_MAX && D_i[edge.from] + edge.cost < D_i[edge.to])
      D_{i+1}[edge.to] = D_i[edge.from] + edge.cost

# repeat to find negative cycle
for(i = 0; i < V - 1; ++i)
  foreach edge in graph:
    if(D[edge.from] == INT_MIN || D[edge.from] + edge.cost < D[edge.to])
      D[edge.to] = INT_MIN
```

**Optimization**: stop early if one outer loop doesn't change any distance

To elaborate on why we do "V-1" iterations, it comes from the following lemma:

> If the shortest path from the source to a node v ends with the edge u->v, and
> we already know the correct distance to u, and then we relax the edge u->v, we
> will find the correct distance to v.

It is a pretty obvious lemma, if you think about it, but the correctness of
Bellman-Ford, Dijkstra, and topological sort are all based on it. The
consequence of this lemma is that, in order to find the correct distance to a
node v, we need to relax all the edges in the shortest path from the source to
v *IN ORDER*. Dijkstra and topological sort are efficient because we only relax
the out-going edges from each node after we found the correct distance for that
node, so we only need to relax the edges once. Unfortunately, the combination
of cycles and negative edges makes it impossible to find a "good" order to
relax the edges. Thus, Bellman-Ford just relaxes all the edges in an arbitrary
order (this is one iteration of Bellman-Ford). In the first iteration, we find
the correct distance for all the nodes whose shortest paths from the source
have 1 edge. In the next iteration, we find the correct distances for all the
nodes whose shortest paths from the source have 2 edges, and so on. If the
shortest path with the most edges has k edges, we need k iterations of Bellman
Ford. Of course, we do not know what "k" is in advance, but, since shortest
paths never repeat nodes (assuming there are no negative cycles), what we know
for sure is that any shortest path will have at most V-1 edges (in the case
where it goes through every node). This is why V-1 iterations is ALWAYS
enough, but often not necessary. If in one iteration of Bellman-Ford no
relaxation yields any improvement, it means that we already found all
shortest paths and we can finish.

https://www.youtube.com/watch?v=lyw4FaxrwHg


## All pairs shortest path

### 3. Floyd-Warshall algorithm (Dynamic Programming)

```pseudo
matrix M: |V| by |V|
fill in M with edges

for each vertex `x` in graph:
  M[x,:] and M[:, x] remains unchanged
  use `x` as the proxy to relax distance:
  for each pair of vertices (u, v):
    if (M[u, v] < M[u, x] + M[x, v]):
      M[u, v] = M[u, x] + M[x, v]
```
