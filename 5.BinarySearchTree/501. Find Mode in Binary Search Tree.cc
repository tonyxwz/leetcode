// https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> ans;
    int freq = 0;
    int max_freq = 0;
    TreeNode* prev = nullptr;
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* node) {
        if(!node) return;
        inorder(node->left);

        if(!prev || prev->val != node->val) {
            freq = 1;
        } else if (prev->val == node->val) {
            freq++;
        }
        if (freq == max_freq){
            ans.push_back(node->val);
        } else if (freq > max_freq) {
            max_freq = freq;
            ans.clear();
            ans.push_back(node->val);
        }

        prev = node;
        inorder(node->right);
    }
};
// ```