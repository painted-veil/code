/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
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
    bool isBalanced(TreeNode* root) {//自顶向上递归，时间复杂度O(n),空间复杂度O(n),这里只用了迭代，
        return getHeigh(root) == -1 ? false : true;
    }
    
    int getHeigh(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeigh(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = getHeigh(node->right);
    if (rightHeight == -1) return -1;
    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
};
// @lc code=end

