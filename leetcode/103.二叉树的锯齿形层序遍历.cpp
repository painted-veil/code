/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        bool left_flag = true;//是否从左至右标志位
        queue<TreeNode*> que;//队列实现BFS按层遍历
        que.push(root);
        while(!que.empty()){
           //定义一个双端队列存储当前层的值，用双端队列是方便按层存值调换方向
           deque<int> dlist;
           //获取当前层值的个数，用来一次遍历完该层
           int n = que.size();
           //遍历队列中该层的值并出队，按标志位存入双端队列，再按固定顺序读取下一层节点值进队列
           for(int i = 0; i < n; i++){
               auto node = que.front();//取节点
               que.pop();//出队
               //按要求存
               if(left_flag){
                   dlist.push_back(node->val);//存入顺序和读取下一层顺序一致
               }else{
                   dlist.push_front(node->val);//反向存入双端队列
               }
               //读取下一层节点值进入队列(左至右)
               if(node->left) que.push(node->left);
               if(node->right) que.push(node->right);
           }
           ans.push_back(vector<int>{dlist.begin(), dlist.end()});//存入ans中，勿忘格式转换
           left_flag = !left_flag;//标志位转换
        }
        return ans;

    }
};
// @lc code=end

