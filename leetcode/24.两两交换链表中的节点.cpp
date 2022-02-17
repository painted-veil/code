/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {//时间复杂度O(n),空间复杂度O(1)
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* p1 = dummyNode;//p1为需交换的节点前面一个节点
        ListNode* p2;////将节点p2与p2->next交换。这样不需要额外记录交换节点之前的节点
        while(p1->next != NULL && p1->next->next != NULL){
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = p2 ->next ->next;
            p1->next->next = p2;
            p1 = p2;
        }
        return dummyNode->next;
    }
};
// @lc code=end

