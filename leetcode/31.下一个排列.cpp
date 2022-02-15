/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
/*
先倒序遍历数组, 找到第一个 (前一个数比后一个数小的位置) (即nums[i] < nums[i+1]);

这个时候我们不能直接把后一个数nums[i+1] 跟前一个数nums[i]交换就完事了; 还应该从nums[i+1]-->数组末尾这一段的数据中 找出最优的那个值( 如何最优? 即比nums[i]稍微大那么一丢丢的数, 也就是 nums[i+1]-->数组末尾中, 比nums[i]大的数中最小的那个值)

找到之后, 跟num[i]交换, 这还不算是下一个排列, num[i]后面的数值还不够小, 所以还应当进升序排列
*/
    void nextPermutation(vector<int>& nums) {
        int firstIndex = -1;
        int n = nums.size();
        for(int i = n -2;i >= 0;i--) {
            if(nums[i] <nums[i+1]) {
                firstIndex = i;
                break;
            }
        }
        if(firstIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int secondIndex = -1;
        for(int i = n -1;i>=firstIndex;i--){
            if(nums[i] >nums[firstIndex]){
                secondIndex = i;
                break;
            }
        }
        swap(nums[firstIndex],nums[secondIndex]);
            int i=firstIndex + 1;
            int j=n-1;
            while(i<j)swap(nums[i++],nums[j--]);

    }
};
// @lc code=end

