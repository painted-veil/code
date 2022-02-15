/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
/*    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        InOrder(root,res);
        return res;
    }
    void InOrder(TreeNode* root,vector<int> &res){
        if(root == nullptr){
            return;
        }
        InOrder(root->left,res);
        res.push_back(root->val);
        InOrder(root->right,res);
    }   
*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur !=nullptr ||!st.empty()){
            if(cur!=nullptr){
                st.push(cur);
                cur=cur->left;
            }else{
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据放进result数组里的数据
                st.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        return result;
    }
};
// @lc code=end

