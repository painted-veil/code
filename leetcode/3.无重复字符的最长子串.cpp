/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> wi;
        int maxStr=0;
        int left = 0;
        for(int i=0; i<s.size(); i++){
            while(wi.find(s[i])!=wi.end()){//find查找对应元素，成功返回对应的迭代器，失败返回最后一个元素迭代器最后添加进去的元素对应的迭代器的下一个
            wi.erase(s[left]);
            left++;
            }
        maxStr = max(maxStr,i-left+1);
        wi.insert(s[i]);
        }

        return maxStr;
    }

};
// @lc code=end

