//
// Created by YuYue on 2021/4/1.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

# include "ListNode.h"

class Solution_142 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }

            fast = fast->next->next;
            if (fast == slow) {
                // 构造第二轮相遇，p指向链表头部
                // 最终在入环点相遇
                ListNode *p = head;
                while (p != slow) {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};