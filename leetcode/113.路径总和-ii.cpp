/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int> > result;
    vector<int> path;
    void traversal(TreeNode* cur,int count){
        if(!cur->left && !cur->right && count == 0){//遇到叶子节点且找到和为Sum 的路径
            result.push_back(path);
            return;
        }
        if(!cur->left &&!cur->right)return;//遇到叶子节点没有找到合适的边则直接返回

        if(cur->left){
            path.push_back(cur->left->val);
            count -=cur->left->val;
            traversal(cur->left,count);//递归
            count +=cur->left->val;
            path.pop_back();//回溯
        }
        if(cur->right){
            path.push_back(cur->right->val);
            count -=cur->right->val;
            traversal(cur->right,count);//递归
            count +=cur->right->val;
            path.pop_back();//
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return result;
        path.push_back(root->val);
        traversal(root,targetSum - root->val);
        return result;
    }
};
// @lc code=end

