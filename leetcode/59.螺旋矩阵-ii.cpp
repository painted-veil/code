/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n,vector<int>(n));//使用vectot定义一个二维数组
    
    int left = 0;
    int right = n-1;
    int top = 0;
    int down = n-1;
    int num = 0;
    while(num<n*n)
    {
      for(int i=left; i<= right; ++i)
      {
          res[top][i]=++num;
      }
      for(int i = top+1;i <= down; ++i)
      {
          res[i][right]=++num;
      }
      for(int i = right-1;i >= left; --i)
      {
          res[down][i]=++num;
      }
      for(int i = down-1;i >= top+1; --i)
      {
            res[i][left]=++num;
      }
      ++top;
      --down;
      --right;
      ++left;
    }
    return res;
    }
};
// @lc code=end

