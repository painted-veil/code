/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> result;//记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s,int startIndex,int pointNum){
        if(pointNum ==3){//逗点为3时分割结束
         // 判断第四段子字符串是否合法，如果合法就放进result中
            if(isValid(s,startIndex,s.size()-1)){
                result.push_back(s);
            }
            return;
        }
        for(int i=startIndex;i<s.size(); i++){
            if(isValid(s,startIndex,i)){// 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin()+ i +1,'.');//在i后面加入一个逗点
                pointNum++; //
                backtracking(s,i+2,pointNum);//插入逗点之后下一个起始位置i+2
                pointNum--;
                s.erase(s.begin()+i+1);//回溯删除逗点
            }else{
                break;//不合法结束循环
            }
        }

    }
    bool isValid(const string& s,int start,int end){//判断字符串s在左闭右闭区间所组成数组是否合法
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start !=end){//0开头数字不合法
            return false;
        }
        int num = 0;
        for(int i = start; i <= end;i++){
            if(s[i]>'9'||s[i]<'0'){
                return false;
            }
            num = num*10+(s[i]-'0');
            if(num > 255){
                return false;
            }
        }
        return true;

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12) return result;//剪枝
        backtracking(s,0,0);
        return result;
    }
};
// @lc code=end

