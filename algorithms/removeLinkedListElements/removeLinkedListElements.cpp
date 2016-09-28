/**
 *
 * Sean
 * 2016-09-28
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode *pp = &fakeHead;
        ListNode *p;
        // invariant: `pp` points to the last element not eqaul to `val`
        while (pp) {
            p = pp->next;
            while (p && p->val == val) {
                p = p->next;
            }
            pp->next = p;
            pp = p;
        }
        return fakeHead.next;
    }
};

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    ListNode one1(1), one2(1);
    one1.next = &one2;
    Solution solution;
    ListNode *removed = solution.removeElements(&one1, 1);
    printList(removed);
}
