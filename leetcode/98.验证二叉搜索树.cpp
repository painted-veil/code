/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
/* 递归写法
    TreeNode* pre = NULL;//用来记录前一个节点
    bool isValidBST(TreeNode* root) {
        if( root == NULL) return true;
        bool left = isValidBST(root->left);

        if(pre!= NULL&&pre->val>=root->val) return false;
        pre = root;//记录前一个节点

        bool right = isValidBST(root->right);
        return left&&right;
    }
    //递归中序遍历将二叉搜索树转变成一个数组
    vector<int> vec;
    void traversal(TreeNode* root){
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val);//转换为一个有序的数组
        traversal(root->right);
    }
    */
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;//记录前一个节点
        while(cur != NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }else{//中
                cur = st.top();
                st.pop();
                if(pre != NULL&&pre->val>=cur->val) return false;
                pre= cur;//保存前一个节点
                cur = cur->right;//右
            }
        }
        return true;
    }
};
// @lc code=end

