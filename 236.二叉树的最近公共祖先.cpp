/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_map>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    unordered_map<int, TreeNode*> map;
    unordered_map<int, bool> vis;
    void searchFa(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            map[root->left->val] = root;
            searchFa(root->left);
        }
        if (root->right) {
            map[root->right->val] = root;
            searchFa(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (!root) return root;
        map[root->val] = nullptr;
        searchFa(root);
        while (p) {
            vis[p->val] = true;
            p = map[p->val];
        }
        while (q) {
            if (vis[q->val]) return q;
            q = map[q->val];
        }
        return root;
    }
};
// @lc code=end

