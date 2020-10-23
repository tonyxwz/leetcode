#include <vector>
using std::vector;
// reminder: in/out degree
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> fluxes(N);
        for(const auto& p: trust) {
            fluxes[p[1]-1]++;
            fluxes[p[0]-1]--;
        }
        int num = 0;
        int ans = 0;
        for(int i = 0; i < N; i++) {
            if (fluxes[i] == N-1) {
                num++;
                ans = i+1;
            }
        }
        if(num != 1)
            return -1;
        else
            return ans;
    }
};
