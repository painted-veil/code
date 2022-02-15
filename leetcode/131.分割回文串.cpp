/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string> > result;
    vector<string> path;
    void backtracking(const string& s,int startIndex){
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIndex >=s.size()){
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size();i++){
            if(isPalindrome(s,startIndex,i)){//判断是否回文子串
                string str = s.substr(startIndex,i-startIndex+1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();//回溯过程弹出本次已经填在的自创
        }
    }
    bool isPalindrome(const string& s,int start,int end){
        for(int i =start,j = end;i<j;i++,j--){
            if(s[i] !=s[j]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
 
};
// @lc code=end

