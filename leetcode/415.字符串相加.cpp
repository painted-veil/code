/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <stack>
class Solution {
public:
    string addStrings(string num1, string num2) {
       int i = num1.length()-1;
       int j = num2.length()-1;
       int add = 0;
       string str= "";
       int x,y;
       while(i>=0 ||j>=0||add!=0){
           if(i>=0)
           {
               x= num1[i]-'0';
           }
           else{
               x =0;
           }
            if(j>=0)
           {
               y= num2[j]-'0';
           }
           else{
               y =0;
           }
           int result = x+y+add;
           str.push_back('0'+ result%10);
           add = result /10;
           --i;
           --j;
       }
       reverse(str.begin(), str.end());
       return str;
        
    }
};
// @lc code=end

