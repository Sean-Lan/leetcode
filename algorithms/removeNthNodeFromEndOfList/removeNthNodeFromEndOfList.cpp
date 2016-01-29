/**
 *
 * Sean
 * 2016-01-29
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 */
#include <cstddef> // for NULL

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        // use two pointers, one move n node ahead first.
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *pastN = head;
            ListNode *pre = head;
            ListNode *cur = NULL;
            int i=0;
            for (; i<=n && pastN; ++i) {
                pastN = pastN->next;
            }
            if (i<=n) { // the list is short
                cur = head;
                head = cur->next;
                if (cur) delete cur;
                return head;
            }
            while (pastN) {
                pastN = pastN->next;
                pre = pre->next;
            }
            cur = pre->next;
            pre->next = cur->next;
            if (cur) delete cur;
            return head;
        }
};
