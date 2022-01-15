/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //快速排序
        int begin = 0;
        int end = nums.size() - 1;
        QuickSort(nums,begin,end);
        return nums;
        
    }
    void QuickSort(vector<int>& nums,int begin,int end){
        if (begin >=end) return;
        int low = begin,high =end,key = nums[begin];
        while(low <high){
            while(low < high&& nums[high] >=key){
                --high;
            }
            if(low < high){
                nums[low++]=nums[high];
            }
            while(low < high&& nums[low] <=key){
                ++low;
            }
            if(low <high){
                nums[high--] = nums[low];
            }
        }
        nums[low] =key;
        QuickSort(nums,begin,low-1);
        QuickSort(nums,low+1,end);
    }
};
// @lc code=end

