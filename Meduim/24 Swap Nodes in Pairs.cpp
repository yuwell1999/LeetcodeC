//
// Created by YuYue on 2021/3/14.
//

#include "ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 递归版本
        // 终止条件是链表中没有节点或者是只有一个节点，此时无法进行交换
        if(head== nullptr || head->next == nullptr){
            return head;
        }

        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;

        //return newHead;

        // 迭代版本
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *temp = dummy;

        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;

            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }

        return dummy->next;
    }
};