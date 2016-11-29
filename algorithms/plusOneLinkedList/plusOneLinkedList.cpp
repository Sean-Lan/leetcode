/**
 *
 * Sean
 * 2016-11-29
 * https://leetcode.com/problems/plus-one-linked-list/
 *
 * Given a non-negative number represented as a singly linked list of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 * Example:
 * Input:
 * 1->2->3
 *
 * Output:
 * 1->2->4
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

// typical dfs.
class Solution {
    bool helper(ListNode *head) {
        if (!head) return true;

        bool carry = helper(head->next);
        if (carry) {
            ++ head->val;
            if (head->val == 10) {
                head->val = 0;
                return true;
            }
        }
        return false;
    }
public:
    ListNode* plusOne(ListNode* head) {
        if (helper(head)) {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};

int main() {
    return 0;
}
