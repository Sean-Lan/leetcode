/**
 *
 * Sean
 * 2016-08-14
 *
 * https://leetcode.com/problems/odd-even-linked-list/
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input.
 * The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *evenHead = head->next;
        ListNode *pOdd = head, *pEven = evenHead, *pCur = evenHead->next;
        while (pCur) {
            pOdd->next = pCur;
            pOdd = pOdd->next;
            pCur = pCur->next;
            if (!pCur) break;
            pEven->next = pCur;
            pEven = pEven->next;
            pCur = pCur->next;
        }
        pOdd->next = evenHead;
        pEven->next = NULL;
        return head;
    }
};

int main() {
    return 0;
}
