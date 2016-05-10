/**
 *
 * Sean
 * 2016-05-10
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode *p = head;
            ListNode *pNext = nullptr;
            while (p) {
                pNext = p->next;
                while (pNext && pNext->val==p->val)
                    pNext = pNext->next;
                p->next = pNext;
                p = pNext;
            }
            return head;
        }
};

int main() {}
