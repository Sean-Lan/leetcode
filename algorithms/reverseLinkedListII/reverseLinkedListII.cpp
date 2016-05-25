/**
 *
 * Sean
 * 2016-05-25
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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

// First move to the node before m-th node, then do pointer swap operation for (n-m) times.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode *p = &fakeHead;
        int cnt = 0;
        while (++cnt < m) {
            p = p->next;
        }
        ListNode *q = p->next;
        ListNode *tmp;
        for (int i=m; i<n; ++i) {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
        }
        return fakeHead.next;
    }
};

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode one(1), two(2), three(3);
    one.next = &two;
    two.next = &three;
    printList(&one);

    Solution solution;
    ListNode *one_r = solution.reverseBetween(&one, 1, 3);
    printList(one_r);
}

