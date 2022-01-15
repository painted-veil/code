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
            while(wi.find(s[i])!=wi.end()){
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

