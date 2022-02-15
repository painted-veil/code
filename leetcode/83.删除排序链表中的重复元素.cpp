/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {//时间复杂度O(n),空间复杂度O(1);
       ListNode *pi = head;
       while(pi&&pi->next){
           if(pi->val == pi->next->val){
               ListNode *del = pi->next;
               pi->next = pi->next->next;
               delete del;
           }else{
               pi = pi->next;
           }
       }
       return head;
    }
};
// @lc code=end

