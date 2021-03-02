#include "leetcode.h"
class DisjointSet {
private:
    vector<int> parents_;
public:
    DisjointSet(int size)
        : parents_{vector<int>(size)}
    {
        iota(parents_.begin(), parents_.end(), 0);
    }
    int find(int x) {
        if (parents_[x] != x)
            parents_[x] = find(parents_[x]);
        return parents_[x];
    }
    void union_(int a, int b) {
        parents_[find(a)] = parents_[find(b)];
    }
};


class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        DisjointSet dj(n+1);
        for(const auto i: A) {
            const int ub = sqrt(i);
            for (int d = 2; d <= ub; ++d) {
                if (i % d == 0) {
                    dj.union_(i, d);
                    dj.union_(i, i / d);
                }
            }
        }
        int ans = 1;
        unordered_map<int, int> size;
        for(const auto i: A)
            ans = max(ans, ++size[dj.find(i)]);
        return ans;
    }

};
