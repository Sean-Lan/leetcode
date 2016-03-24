/**
 *
 * Sean
 * 2016-03-24
 *
 * https://leetcode.com/problems/rotate-list/
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
        ListNode* rotateRight(ListNode* head, int k) {
            if (!head) return nullptr;

            // calculate the len of the list.
            ListNode *tmp = head;
            int len = 1;
            while (tmp->next) {
                ++len;
                tmp = tmp->next;
            }
            // the `tmp` now is the end of the list.

            k %= len;
            if (k == 0)
                return head;

            // link the end to `head` by the way.
            tmp->next = head;

            // move to the new head.
            int cnt = len-k;
            ListNode *prev = nullptr;
            tmp = head;
            while (cnt--) {
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = nullptr;
            ListNode *newHead = tmp;

            return newHead;
        }
};

void printList(ListNode *head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    Solution solution;
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    one->next = two;
    auto newHead = solution.rotateRight(one, 0);
    printList(newHead);
}
