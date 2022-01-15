/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>//sort所需头文件
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int subLength  = 0;//截取字符串的长度，滑动窗口的长度
        int sum = 0;//滑动窗口的数值
        int i = 0;//初始窗口的位置
        int result = INT32_MAX;
        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum >= target){//注意这里有while 循环但是不是On的平方复杂度，因为只是比一次就抛出，因此总的复杂度为2* O(n)
                subLength  = j - i + 1;
                result = result <subLength ? result : subLength;
                sum -=nums[i];//这两步就是滑动窗口的精髓
                i++;//将滑动窗口的起始移动一个单位
                
            }
        }
        return result ==INT32_MAX ? 0 : result;





    }
};
// @lc code=end

