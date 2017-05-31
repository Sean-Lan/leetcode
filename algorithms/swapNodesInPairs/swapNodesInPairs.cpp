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
        if (!head || !head->next) return head;
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode *p0 = &fakeHead;
        ListNode *p1, *p2;
        while ((p1 = p0->next) && (p2 = p1->next)) {
            p0->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            p0 = p1;
        }
        return fakeHead.next;
    }
};

int main() {
    return 0;
}
