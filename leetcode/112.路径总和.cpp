/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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

    bool traversal(TreeNode* cur,int count) {//时间复杂度O(n),空间负载度O(height),平均空间复杂度为O(logN)
        if(!cur->left && !cur->right && count == 0) return true;//遇到叶子节点且计数为0
        if(!cur->left && !cur->right) return false;//

        if(cur->left){
            count -= cur->left->val;
            if(traversal(cur->left,count))return true;
            count +=cur->left->val;//回溯撤销处理结果
        }
        if(cur->right){
            count -=cur->right->val;
            if(traversal(cur->right,count)) return true;
            count +=cur->right->val;//回溯撤销处理结果

        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return traversal(root, targetSum-root->val);
    }
};
// @lc code=end

