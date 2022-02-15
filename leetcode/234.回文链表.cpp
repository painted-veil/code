/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {//时间复杂度O(n),空间复杂度O(1)；
        ListNode* slow = head, *fast = head,*pre = nullptr;
        while(fast){//快指针走到末尾，慢指针刚好走到中间
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;   
        }
        while(slow){//反转
            ListNode* temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        while(head &&pre){
            if(head->val !=pre->val){
                return false;
            }
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end

