/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return false;
        stack<char> sta;
        for(auto c : s){
            if(c == '('||c =='['|| c =='{')
            {
                sta.push(c);
            }
            else{
                if(!sta.empty()){
                    if(c=='}')
                    {
                        if(sta.top() != '{')
                            return false;
                    }
                    else if(c==']')
                    {
                        if(sta.top() != '[')
                            return false;
                    }
                    else if(c ==')')
                    {
                        if(sta.top() != '(')
                            return false;
                    }
                    sta.pop();
                }
                else//如果不为空还进来除([{的符号
                {
                    return false;
                }

            }
        }
        return sta.empty();

    }
};
// @lc code=end

