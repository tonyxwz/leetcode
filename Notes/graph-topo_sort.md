# Topological sorting

Only meaningful on DAG (Directed Acyclic Graph)
In topological order, a node must appear after its neighbours, in this case the edges means dependency relations.

How to remember: **Depth first searching**

traverse all nodes, if unvisited, dfs

```cpp
vector<int> topsort(const vector<vector<int>>& graph) {

}
```

```
topsort(graph):
  visited: array of false, len=graphSize
  order:array of node, len=graphSize
  i:int = len(graph.nodes) - 1

  foreach node in graph:
    if node is not visited;
      dfs(node, &i, &order, &visited)


dfs(node, &i, &order, &visited):
  if (visitied[node]) // boundary condition
    return;
  visited[node] = true
  foreach neighbour of node:
    dfs(neighbour, &i)

  order[i] = node
  i = i - 1;
```
