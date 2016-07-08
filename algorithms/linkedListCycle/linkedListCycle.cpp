/**
 *
 * Sean
 * 2016-07-08
 *
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
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

// Use fast and slow pointers.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            if (fast == slow) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main() {}
