/**
 *
 * Sean
 * 2016-07-27
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Note: Do not modify the linked list.
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

// Using two pointers.
// Reference to https://discuss.leetcode.com/topic/2975/o-n-solution-by-using-two-pointers-without-change-anything
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (!fast || !fast->next) return NULL;

        ListNode *p1 = head;
        ListNode *p2 = fast;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main() {
    return 0;
}
