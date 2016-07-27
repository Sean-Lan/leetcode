/**
 *
 * Sean
 * 2016-07-27
 *
 * https://leetcode.com/problemset/algorithms/
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        int cnt = 0;
        ListNode *p1 = head;
        // count the list
        while (p1) {
            ++cnt;
            p1 = p1->next;
        }
        cnt >>= 1;
        if (cnt == 0) return;

        // move p2 to the second half
        ListNode *p2 = head;
        while (cnt --) {
            p2 = p2->next;
        }
        ListNode *tmp = p2->next;
        // remember to set the end of first half to NULL
        p2->next = NULL;
        p2 = tmp;

        // reverse the second half
        p2 = reverseList(p2);

        // insert the second half into the first half
        p1 = head;
        while (p2) {
            tmp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next  = tmp;
            p1 = tmp;
        }
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *p1 = NULL;
        ListNode *p2 = head;
        ListNode *tmp;
        while (p2) {
            tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
};

int main() {
    return 0;
}
