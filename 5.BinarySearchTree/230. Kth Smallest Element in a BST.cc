// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#include "leetcode.h"

// ```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // in order
        stack<TreeNode*> s;
        do {
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();s.pop();
            if (0 == --k)
                return root->val;
            root = root->right;
        } while(!s.empty() || root != nullptr);
        return -1;
    }
};
// ```