/**
 *
 * Sean
 * 2016-05-25
 *
 * https://leetcode.com/problems/reverse-linked-list/
 *
 * Reverse a singly linked list.
 *
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) { // iterative version
        if (!head || !head->next) return head;
        ListNode fakeHead = ListNode(0);
        fakeHead.next = head;
        ListNode *p = head;
        ListNode *q;
        while ((q = p->next)) {
            p->next = q->next;
            q->next = fakeHead.next;
            fakeHead.next = q;
        }
        return fakeHead.next;
    }

    ListNode* reverseList2(ListNode *head) { // Another iterative version, more intuitive.
        if (!head || !head->next) return head;
        ListNode *rHead = head;
        ListNode *p = head->next;
        head->next = nullptr;
        ListNode *tmp;
        while (p) {
            tmp = p->next;
            p->next = rHead;
            rHead = p;
            p = tmp;
        }
        return rHead;
    }

    ListNode* reverseList_r(ListNode* head) { // recursive version
        auto aPair = reverseHelper(head);
        return aPair.first;
    }

    pair<ListNode *, ListNode *> reverseHelper(ListNode *head) {
        if (!head || !head->next) return {head, head};
        auto aPair = reverseHelper(head->next);
        if (aPair.second) {
            aPair.second->next = head;
        }
        head->next = NULL;
        return {aPair.first, head};
    }

    ListNode* reverseList_r2(ListNode *head) { // a more succint recursive version.
        if (!head || !head->next) return head;
        auto newHead = reverseList_r2(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

int main() {}
