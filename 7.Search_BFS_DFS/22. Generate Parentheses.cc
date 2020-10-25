#include <string>
#include <vector>
using namespace std;

class Solution
{
    void dfs(vector<string>& ans, string& curr, const int n, int left, int right) {
        if(left == n && right == n) {
            ans.push_back(curr);
            return;
        }
        if (left < n) {
            curr.push_back('(');
            dfs(ans, curr, n, left+1, right);
            curr.pop_back();
        }
        if (right < left) {
            curr.push_back(')');
            dfs(ans, curr, n, left, right+1);
            curr.pop_back();
        }
    }
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        dfs(ans, curr, n, 0, 0);
        return ans;
    }
};
