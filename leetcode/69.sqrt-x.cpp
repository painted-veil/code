/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {//二分查找
        if(x == 1)
            return 1;
        int min = 0;
        int max = x;
        while(max - min >1){
            int m =(max + min)/2;
            if(x/m<m){//如果使用m*m防止溢出
                max = m;
            }else{
                min = m;
            }
        }
        return min;
    }
};
// @lc code=end

