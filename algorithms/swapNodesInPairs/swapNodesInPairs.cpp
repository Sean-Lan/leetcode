/**
 *
 * Sean
 * 2016-02-02
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list,
 * only nodes itself can be changed.
 *
 */

#include <cstddef>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (!head) return NULL;
            ListNode fakeHead = ListNode(0);
            fakeHead.next = head;
            ListNode *p1 = &fakeHead;
            ListNode *p2 = p1->next;
            ListNode *p3 = p2->next;
            while (p1 && p2 && p3) {
                p1->next = p3;
                p2->next = p3->next;
                p3->next = p2;
                p1 = p2;
                if (!p2->next) break;
                p2 = p2->next;
                p3 = p2->next;
            }
            return fakeHead.next;
        }
};
