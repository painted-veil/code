/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {//双指针，时间复杂度为O(n+m)
        int i = 0, j = 0;
        while( i < version1.length() || j < version2.length()){//注意这里是||
            int num1 = 0, num2 = 0;
            while(i < version1.length() && version1[i]!='.') num1 = num1 *10 +version1[i++] - '0';
            while(j < version2.length() && version2[j]!='.') num2 = num2 *10 +version2[j++] - '0';
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            i++;
            j++;
        }
        return 0;
        
    }
};
// @lc code=end

