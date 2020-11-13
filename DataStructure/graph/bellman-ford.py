"""
Helper reminder:
relax all the vertice n-1 times
relaxation:
for i in range(n-1):
    for edge (u, v):
        if d(v) > d(u) + weight(u, v):
            d(v) = d(u) + weight(u, v)
"""