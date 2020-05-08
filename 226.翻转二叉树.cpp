/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
#include<queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        TreeNode* head = root;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            swap(tmp->left, tmp->right);
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        return head;
    }
};
// @lc code=end

