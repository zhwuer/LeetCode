/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
#include <stack>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    bool isIdentical(TreeNode* s, TreeNode* t) {
        if (s && t) {
            return (s->val == t->val) && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
        } else {
            return s == t;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        stack<TreeNode*> st;
        st.push(s);
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            if (isIdentical(tmp, t)) return true;
            if (tmp) {
                // cout << tmp->val << endl;
                st.push(tmp->right);
                st.push(tmp->left);
            }
        }
        return false;
    }
};
// @lc code=end

