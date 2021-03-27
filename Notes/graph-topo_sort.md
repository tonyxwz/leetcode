How to remember: **Depth first searching**

traverse all nodes, if unvisited, dfs

topsort(graph):
  visited: array of false, len=graphSize
  order:array of node, len=graphSize
  i:int = len(graph.nodes) - 1

  foreach node in graph:
    if node is not visited;
      dfs(node, &i, &order, &visited)


dfs(node, &i, &order, &visited):
  visited[node] = true
  foreach neighbour of node:
    dfs(neighbour, &i)

  order[i] = node
  i = i - 1;