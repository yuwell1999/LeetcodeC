//
// Created by YuYue on 2021/5/10.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "ListNode.h"

using namespace std;

class Solution_jz22 {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        // 空指针
        // k<0
        // 节点数小于k
        if (head == nullptr || k <= 0) {
            return nullptr;
        }
        ListNode *fast = head, *slow = head;

        for (int i = 0; i < k; i++) {
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};