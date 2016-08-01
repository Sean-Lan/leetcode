/**
 *
 * Sean
 * 2016-08-01
 *
 * Sort a linked list using insertion sort.
 *
 */
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pp1;
        ListNode *p1;
        ListNode *pp2 = head;
        ListNode *p2 = head->next;
        while (p2) {
            pp1 = p1 = head;
            if (pp2->val <= p2->val) { // need not to move p2 backward.
                pp2 = p2;
                p2 = p2->next;
                continue;
            }

            // move p2 to somewhere before it.
            while (p1->val < p2->val) {
                pp1 = p1;
                p1 = p1->next;
            }

            pp2->next = p2->next;
            if (pp1 == p1) { // p1 is the head
                p2->next = p1;
                head = p2;
            } else {
                pp1->next = p2;
                p2->next = p1;
                pp1 = p2;
            }
            p2 = pp2->next;
        }
        return head;
    }
};
int main() {
    return 0;
}
