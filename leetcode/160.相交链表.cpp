/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr|| headB == nullptr) return nullptr;

        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa !=pb){
            pa = pa == nullptr? headA : pa->next;
            pb = pb == nullptr? headB : pb->next;
        }
        return pa;
    }
};
// @lc code=end

