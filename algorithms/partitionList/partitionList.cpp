/**
 *
 * Sean
 * 2016-03-14
 *
 * https://leetcode.com/problems/partition-list/
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode *less = new ListNode(-1); // fake head
        ListNode *greaterOrEqual = new ListNode(-1);
        ListNode *p1 = less, *p2 = greaterOrEqual;
        while (head) {
            if (head->val<x) {
                p1->next = head;
                p1 = head;
            } else {
                p2->next = head;
                p2 = head;
            }
            head = head->next;
        }
        p1->next = greaterOrEqual->next;
        p2->next = nullptr;
        return less->next;
    }
};

int main() {
}
