/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {//时间复杂度O(n),空间复杂度O(n);
        return dfs(root,0);
    }
    int dfs(TreeNode* root,int preSum){
        if(root ==NULL) return 0;
        int sum = preSum * 10 +root->val;
        if(root->left == nullptr && root->right == nullptr){
            return sum;
        }else{
            return dfs(root->left,sum) + dfs(root->right,sum);
        }
    }
};
// @lc code=end

