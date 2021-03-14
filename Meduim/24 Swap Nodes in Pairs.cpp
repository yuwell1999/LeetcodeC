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

        return newHead;

        // 迭代版本

    }
};