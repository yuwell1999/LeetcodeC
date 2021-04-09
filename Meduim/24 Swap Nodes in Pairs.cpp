//
// Created by YuYue on 2021/3/14.
//

#include "ListNode.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // 递归版本
        // 终止条件是链表中没有节点或者是只有一个节点，此时无法进行交换
        if (head == nullptr || head->next == nullptr) {
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

        // 每次需要交换temp后面的两个节点
        while (temp->next != nullptr && temp->next->next != nullptr) {
            // 获取需要更新的两个节点
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;

            // 更新节点的指针关系实现两两交换
            temp->next = node2; // node2接到temp后
            node1->next = node2->next; // 断开的节点连到后续
            node2->next = node1; // node1变成node2的后继

            // 对链表中其余两两节点进行交换
            temp = node1;
        }

        return dummy->next;
    }
};