/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {//时间复杂度O(n),空间复杂度O(1);
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         //因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
         ListNode *dummyNode = new ListNode(-1);
         dummyNode->next = head;

         ListNode *pre = dummyNode;
        // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
        for(int i = 0;i<left -1 ;i++){
            pre = pre->next;
        }
        // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
        ListNode *rightNode = pre;
        for(int i = 0;i<right - left +1;i++){
            rightNode = rightNode->next;
        }

        // 第 3 步：切断出一个子链表（截取链表）
        ListNode *leftNode = pre->next;
        ListNode *cur = rightNode->next;

        //切断连接
        pre->next = nullptr;
        rightNode->next = nullptr;

        //反转链表子区间
        reverseLinkedList(leftNode);

        //接回原来的链表
        pre->next = rightNode;
        leftNode->next = cur;
        return dummyNode->next;

    }
    void reverseLinkedList(ListNode* head){
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while(cur !=nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
};
// @lc code=end

