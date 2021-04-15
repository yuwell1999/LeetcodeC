//
// Created by YuYue on 2021/4/15.
//

#include "../Meduim/ListNode.h"

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
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分尾节点并反转后半部分链表
        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfEnd = reverseLinkedList(firstHalfEnd->next);

        // 判断是否回文
        ListNode *p1 = head;
        ListNode *p2 = secondHalfEnd;

        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 还原链表并返回结果
        firstHalfEnd->next = reverseLinkedList(secondHalfEnd);

        return result;
    }

    ListNode *reverseLinkedList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while (cur != nullptr) {
            ListNode *tmp = cur->next; // 暂存下一个节点
            cur->next = prev; // 头插法
            prev = cur;
            cur = tmp; // 更新cur指针
        }
        return prev;
    }

    // 找到链表中间元素
    ListNode *endOfFirstHalf(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
