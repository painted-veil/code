/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
      vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size() -1;
        int k = nums.size() -1;
        vector<int> result(nums.size());//创建一个同等大小的vector数组
        while (i <= j){//这里必须要i<=j，为了最后一个元素放入数组中，否则无法处理中间元素，刚好等于的时候就是最后一个元素，
            if(nums[i] * nums[i] >= nums[j] * nums[j]){
                result[k]= nums[i] * nums[i];
                i++;
                k--;
            }
            else {
                result[k]=nums[j] * nums[j];
                j--;
                k--;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            cout<<result[i]<<" ";
        }
        return result;
    }
};
/*class Solution {//暴力解法  :O(n) + O(log(n)) 
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] <<" ";
        }
        return nums;
    }
};*/
// @lc code=end

