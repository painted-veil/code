/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {//双指针 O(N^3)
    vector<vector<int>> result;
    int size = nums.size();
    if(size < 4)
        return result;
    sort(nums.begin(), nums.end());
    for(int k = 0; k<nums.size();k++){
        //注意这里target是任意值
        if(k>0&&nums[k]==nums[k-1]){
            continue;
        }
        for(int i = k +1;i<nums.size();i++){
            if(i>k+1&&nums[i] ==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right =nums.size() -1;
            while(right > left){
                //int sum = nums[k]+nums[i] +nums[left] +nums[right];通过sum来判断的话会出现案例溢出的错误
                if(nums[k]+nums[i]> target-(nums[left]+nums[right])){
                    right--;
                }else if(nums[k]+nums[i]< target-(nums[left]+nums[right])){
                    left++;
                }else{
                    result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
                    while(right > left &&nums[right] == nums[right - 1]) right--;
                    while(right >left && nums[left] == nums[left + 1]) left++;
                    left++;
                    right--;
                }
            }  
        }
    }
    return result;
    }
};
// @lc code=end

