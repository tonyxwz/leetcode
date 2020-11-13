"""
remember helper:
construct a matrix D of all the edges:
    diagonals being 0
    D[i, j] is the weight of edge from i to j
based on matrix D:
    use vertex m as middle person:
    if D[i, j] > D[i, m] + D[m, j]:
        update D[i, j]


pseudo-code:
D = zeros(n, n)
for edges in graph:
    D[edges.u, edges,v] = edges.weight

for m in vertices:
    for i in vertices:
        if i == m: continue
        for j in vertices:
            if j == m: continue
            if D[i, j] > D[i, m] + D[m, j]:
                D[i, j] = D[i, m] + D[m, j]
"""