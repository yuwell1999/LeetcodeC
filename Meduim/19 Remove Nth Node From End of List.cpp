//
// Created by YuYue on 2021/3/14.
//
#include "ListNode.h";

class Solution_19 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = head;
        ListNode *slow = dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // 此时slow是倒数第n个节点的前驱
        slow->next = slow->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};