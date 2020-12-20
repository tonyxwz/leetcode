import collections


class DSU:
    def __init__(self):
        self.p = list(range(10001))
        self.rank = [0] * 10001

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])

        return self.p[x]

    def union(self, a, b):
        self.p[self.find(a)] = self.find(b)

    def union_by_rank(self, a, b):
        pa = self.find(a)
        pb = self.find(b)
        if pa == pb:
            return False
        if self.rank[pa] > self.rank[pb]:
            self.p[b] = pa
        elif self.rank[pa] < self.rank[pb]:
            self.p[a] = pb
        else:
            self.p[b] = pa
            self.rank[pa] += 1
        return True


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        dsu = DSU()
        em_to_name = {}
        em_to_id = {}
        i = 0

        for acc in accounts:
            name = acc[0]

            for email in acc[1:]:
                em_to_name[email] = name

                if email not in em_to_id:
                    em_to_id[email] = i
                    i = i + 1
                dsu.union(em_to_id[acc[1]], em_to_id[email])

        ans = collections.defaultdict(list)

        for email in em_to_name:
            ans[dsu.find(em_to_id[email])].append(email)

        return [[em_to_name[v[0]]] + sorted(v) for v in ans.values()]
