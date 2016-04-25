/**
 * 
 * Sean
 * 2016-04-25
 *
 * https://leetcode.com/problems/palindrome-linked-list/
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 */
#include <iostream>
using namespace std;


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// reverse the second half of the list.
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            // calculate the length of the list
            ListNode *p = head;
            int n = 0;
            while (p) {
                ++n;
                p = p->next;
            }
            if (n == 0 || n == 1)
                return true;

            // mid is the one previous to mid
            // since we need to revert to orginal list.
            int mid = n/2-1;
            p = head;
            while (mid--) p = p->next;

            // revsere the second half
            ListNode *pMid = p;
            ListNode *reversed = reverseList(pMid->next);
            pMid->next = nullptr;
            bool isEqual = true;
            ListNode *q = reversed;
            p = head;
            while (p!=nullptr && q!=nullptr) {
                if (p->val != q->val) {
                    isEqual = false;
                    break;
                }
                p = p->next;
                q = q->next;
            }

            // revert to the orginal list
            q = reverseList(reversed);
            pMid->next = q;
            return isEqual;
        }

    private:
        ListNode* reverseList(ListNode *head) {
            if (!head) return nullptr;
            ListNode *p = head;
            ListNode *pNext = p->next;
            ListNode *tmp = pNext;
            while (pNext) {
                tmp = pNext;
                pNext = pNext->next;
                tmp->next = p;
                p = tmp;
            }
            head->next = nullptr;
            return p;
        }
};

void printList (ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode one(1), two(2), three(3), two2(2), one2(1);
    one.next = &two;
    two.next = &three;
    three.next = &two2;
    two2.next = &one2;
    Solution solution;
    cout << solution.isPalindrome(&one) << endl;
}
