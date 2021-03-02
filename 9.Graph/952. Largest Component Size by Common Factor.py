import math
import collections
from typing import *


class Djs:
    parents: List[int]
    size: List[int]

    def __init__(self, size: int) -> None:
        self.parents = list(range(size))
        self.size = [1] * size

    def union(self, a, b):
        pa = self.find(a)
        pb = self.find(b)
        if (pa == pb): return False
        if self.size[pa] < self.size[pb]:
            self.parents[pa] = pb
            self.size[pb] += self.size[pa]
        else:
            self.parents[pb] = pa
            self.size[pa] += self.size[pb]
        return True

    def find(self, x) -> int:
        if (self.parents[x] != x):
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]


def prime_gen(lb: int, ub: int):
    for x in range(max(lb, 2), ub):
        has_factor = False
        for p in range(2, int(math.sqrt(x)) + 1):
            if x % p == 0:
                has_factor = True
                break
        if not has_factor:
            yield x

# works but tle
class Solution:
    factors: List[Set[int]]

    def largestComponentSize(self, A: List[int]) -> int:
        djs = Djs(len(A))
        self.factors = [set()] * len(A)
        for i in range(len(A)):
            for j in range(i + 1, len(A)):
                if (gcd := self.get_gcd(A[i], A[j])) > 1:
                    djs.union(i, j)
        for i in range(len(A)):
            djs.find(i)
        return max(djs.size)

    def get_gcd(self, a, b) -> int:
        ub = min(a, b) + 1
        primes = prime_gen(0, ub)
        factors = []
        for i in primes:
            if a % i == 0 and b % i == 0:
                factors.append(i)
                a = a / i
                b = b / i

        i = 1
        for f in factors:
            i = i * f
        return i


class Solution2:
    def largestComponentSize(self, A):
        p = list(range(max(A) + 1))

        def find(x):
            while p[x] != x:
                p[x] = p[p[x]]
                x = p[x]
            return x

        def union(x, y):
            p[find(x)] = p[find(y)]

        for a in A:
            for k in range(2, int(math.sqrt(a) + 1)):
                if a % k == 0:
                    union(a, k)
                    union(a, a // k)

        return collections.Counter([find(a) for a in A]).most_common(1)[0][1]


if "__main__" == __name__:
    sol = Solution()
    sol2 = Solution2()
    A = [
        342, 521, 258, 526, 528, 534, 27, 32, 550, 92, 48, 55, 581, 73, 74, 75,
        591, 594, 90, 604, 97, 620, 109, 627, 121, 644, 141, 365, 146, 676,
        168, 685, 694, 184, 700, 702, 704, 214, 728, 232, 756, 759, 760, 768,
        770, 263, 779, 275, 788, 278, 132, 803, 813, 302, 305, 306, 310, 312,
        313, 828, 319, 840, 845, 854, 344, 353, 354, 355, 658, 882, 374, 893,
        16, 384, 899, 390, 404, 405, 412, 925, 439, 587, 964, 973, 465, 981,
        473, 475, 996, 998, 490, 498, 442
    ]
    print("correct" if sol.largestComponentSize(A) ==
          sol2.largestComponentSize(A) else "wrong")
