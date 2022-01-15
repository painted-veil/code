/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int SlowIndex = 0;
        int FastIndex = 0;
        for(FastIndex; FastIndex < nums.size(); FastIndex++){
            if(val != nums[FastIndex]){
                nums[SlowIndex] = nums[FastIndex];
                SlowIndex++;
            }
        }
        return SlowIndex;
    }
};
/*class Solution {//关于暴力解法移除元素
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] == val) {
                for(int j = i; j < size - 1; j++){
                    nums[j] = nums[j+1];
                }
            i--;
            size--;//i--和size--一定要放在if条件内
            }
        }
        return size;
    }
};*/
// @lc code=end

