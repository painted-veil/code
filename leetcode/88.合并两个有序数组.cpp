/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len1= m - 1,len2 = n - 1;
        int tail = m + n -1;
        int cur;
        while(len1 >=0 && len2 >= 0){
            if(nums1[len1] > nums2[len2]){
                nums1[tail--] = nums1[len1--];
            }
            else{
                nums1[tail--] = nums2[len2--];
            }
        }
        while(len1 >= 0){
            nums1[tail--] = nums1[len1--];
        }
        while(len2 >= 0){
            nums1[tail--] = nums2[len2--];
        }
    }
};
// @lc code=end

