/**
 *
 * Sean
 * 2017-01-04
 *
 * https://leetcode.com/problems/add-two-numbers-ii/
 *
 * You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    // return { pointer to next node, whether the next node gets carry }
    pair<ListNode *, bool> addHelper(ListNode *l1, ListNode *l2, int m, int n) {
        if (m == 0 && n == 0)
            return { nullptr, false};
        pair<ListNode *, bool> aPair;
        ListNode *cur = new ListNode(0);
        if (m > n) {
            aPair = addHelper(l1->next, l2, m-1, n);
            cur->val += l1->val;
        } else if (m < n) {
            aPair = addHelper(l1, l2->next, m, n-1);
            cur->val += l2->val;
        } else {
            aPair = addHelper(l1->next, l2->next, m-1, n-1);
            cur->val += l1->val + l2->val;
        }
        cur->val += aPair.second;
        bool cnt = cur->val/10;
        cur->val %= 10;
        cur->next = aPair.first;
        return {cur, cnt};
    }

    int getLength(ListNode *l) {
        if (!l) return 0;
        int cnt = 0;
        while (l) {
            ++cnt;
            l = l->next;
        }
        return cnt;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int m = getLength(l1);
        int n = getLength(l2);
        auto aPair = addHelper(l1, l2, m, n);
        ListNode *head = nullptr;
        if (aPair.second) {
            head = new ListNode(1);
            head->next = aPair.first;
        } else {
            head = aPair.first;
        }
        return head;
    }
};
