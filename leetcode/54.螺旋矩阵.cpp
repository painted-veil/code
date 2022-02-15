/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans;
        int u =0;//赋值上下左右边界
        int d = matrix.size() -1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true) {
            for(int i =l;i<=r;i++) ans.push_back(matrix[u][i]);//向右移动到最后
            if(++u > d) break;//重新设定上边界
            for(int i =u;i<=d;i++) ans.push_back(matrix[i][r]);//向下
            if(--r<l) break;//重新设定右边界
            for(int i =r;i>=l;i--) ans.push_back(matrix[d][i]);//向左
            if(--d <u )break;//重新设定下边界
            for(int i =d;i>=u;i--) ans.push_back(matrix[i][l]);//向上
            if(++l >r) break;//重新设定左边界
        }
        return ans;
    }
};
// @lc code=end

