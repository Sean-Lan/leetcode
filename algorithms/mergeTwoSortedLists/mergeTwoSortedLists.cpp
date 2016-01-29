/**
 *
 * Sean
 * 2016-01-29
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 */

#include <cstddef>
// definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode fakeHead = ListNode(0);
        ListNode *head = &fakeHead; // fake head
        ListNode *pCur = head;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                pCur->next = p1;
                p1 = p1->next;
            } else {
                pCur->next = p2;
                p2 = p2->next;
            }
            pCur = pCur->next;
        }

        // copy the remaining
        if (p1) pCur->next = p1;
        if (p2) pCur->next = p2;
        return head->next;
    }
};
