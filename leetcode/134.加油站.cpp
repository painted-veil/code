/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
/*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {//暴力法，时间复杂度为O(n^2),空间复杂度为O(n);
    for (int i = 0; i < cost.size(); i++) {
        int rest = gas[i] - cost[i];
        int index = (i + 1) % cost.size();
        while(rest > 0 && index !=i){//模拟以i为起点行驶一圈
            rest +=gas[index] - cost[index];
            index = (index + 1) % cost.size();
        }
        if(rest >= 0 && index == i ) return i;
    }
    return -1;

    }
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){//时间复杂度O(n),空间复杂度O(1);
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0; i<gas.size(); i++){
            curSum +=gas[i] - cost[i];
            totalSum+=gas[i] - cost[i];
            if(curSum <0){
                start = i +1;
                curSum = 0;
            }
        }
        if(totalSum <0) return -1;
        return start;
    }

};
// @lc code=end

