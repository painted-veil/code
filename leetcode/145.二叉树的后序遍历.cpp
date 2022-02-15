/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
/*
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal(root,res);
        return res;
    }
    void postorderTraversal(TreeNode* root,vector<int> &res){
        if(root == nullptr) return;
        postorderTraversal(root->left,res);
        postorderTraversal(root->right,res);
        res.push_back(root->val);

    }
    */
    vector<int> postorderTraversal(TreeNode* root) {
        stack <TreeNode*> st;
        vector<int> res;
        if(root == NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node ->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;



    }
};
// @lc code=end

