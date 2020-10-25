#include <string>
#include <vector>
using namespace std;

class Solution {
    bool isValid(const string& s) {
        int tot = 0;
        for (const char ch: s) {
            if (ch == '(') ++tot;
            else if (ch == ')') --tot;
            if (tot < 0) return false;
        }
        return tot == 0;
    }

    void dfs(string s, vector<string>& ans, int start, int l, int r) {
        // 与暴力求解不同 这个dfs遍历的是本别去掉l个左括号和r个右括号的结果
        // 超过了指定的数量而且是无效的就停止（剪枝算法）
        if (r == 0 && l == 0) {
            if (isValid(s))
                ans.push_back(s);
            return;
        }
        for(int i = start; i < s.length(); ++i) {
            // 对当前字符串 尝试删除每一个括号字符
            // 并把删除后的字符串传给下一个迭代
            // ! 每一个迭代只删除一个字符
            if (s[i] == '(' || s[i] == ')') {
                if (i > start && s[i] == s[i-1])
                    continue;
                string curr = s;
                curr.erase(i, 1);
                if ( r > 0 && s[i] == ')' ) 
                    dfs(curr, ans, i, l, r-1);
                else if (l > 0 && s[i] == '(')
                    dfs(curr, ans, i, l-1, r);
            }
        }
    }
    public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        // 计算需要分别去掉多少个左、右括号
        for(const char ch : s) {
            if (ch == '(')
                ++l;
            else if (ch == ')') {
                if (l == 0)
                    ++r;
                else
                    --l;
            }
        }
        vector<string> ans;
        dfs(s, ans, 0, l, r);
        return ans;
    }
};
