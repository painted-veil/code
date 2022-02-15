/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() ==0) return result;
        sort(intervals.begin(), intervals.end(),cmp);
        bool flag = false;
        int len = intervals.size();
        for(int i =1;i<len;i++) {
            int start = intervals[i-1][0];
            int end = intervals[i-1][1];
            while(i<len && intervals[i][0]<=end){
                end =max(end,intervals[i][1]);//不断更新右区间
                if(i ==len - 1) flag=true;//最后一个区间也合并了
                i++;//继续合并下一个区间
            }
            //start,end表示是intervals[i-1]的左边界和右边界，所以最优Interbals[i]区间合并要标记
            result.push_back({start,end});
        }
        //如果最后一个区间没有合并，将其加入result
        if(flag == false){
            
            result.push_back({intervals[len-1][0],intervals[len-1][1]});
        }
    return result;
    }
};
// @lc code=end

