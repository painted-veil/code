/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
         removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        for(int i = 0; i < s.size(); i++) {
            int j = i;
            // 查找单词间的空格，翻转单词
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
    void reverse(string &s,int start,int end){
        for(int i =start,j = end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    void removeExtraSpaces(string &s){//O(n)
        int slowindex = 0,fastIndex = 0;//定义快慢指针
        //去掉字符串前面的空格
      while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for(;fastIndex<s.size();fastIndex++){//'去掉中间部分多余空格，使用erase则是O(n^2),earse本身是O(n)
            if(fastIndex -1 >0 &&s[fastIndex-1]==s[fastIndex]&&s[fastIndex]==' '){
                continue;
            }else{
                s[slowindex++] = s[fastIndex];
            }
        }
        if(slowindex -1 >0 && s[slowindex - 1]==' '){//去掉字符串末尾的空格
            s.resize(slowindex - 1);
        }else{
            s.resize(slowindex);
        }
    }
};
// @lc code=end

