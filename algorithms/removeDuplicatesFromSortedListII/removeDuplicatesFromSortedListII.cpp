/**
 *
 * Sean
 * 2016-05-10
 *
 * https://leetcode.com/submissions/detail/61137681/
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 *  Given 1->2->3->3->4->4->5, return 1->2->5.
 *  Given 1->1->1->2->3, return 2->3.
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

// A little trick is to use the fake head.
// Use a flag to mark whether it is dup.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode fakeHead(0);
        ListNode *pPrev = &fakeHead;
        ListNode *p = head;
        ListNode *pNext = nullptr;
        bool isDup;
        while (p) {
            pNext = p->next;
            isDup = false;
            while (pNext && pNext->val == p->val) {
                pNext = pNext->next;
                isDup = true;
            }
            if (!isDup) {
                pPrev->next = p;
                pPrev = p;
            }
            p = pNext;
        }
        pPrev->next = nullptr;
        return fakeHead.next;
    }
};

void printList(ListNode *head) {
    bool isFirst = true;
    while (head) {
        cout << (isFirst?"":"->") << head->val;
        head = head->next;
        isFirst = false;
    }
    cout << endl;
}

int main() {
    ListNode one1(1);
    ListNode one2(1);
    ListNode two(2);
    one1.next = &one2;
    one2.next = &two;
    printList(&one1);

    Solution solution;
    ListNode *gibbed = solution.deleteDuplicates(&one1);
    printList(gibbed);
}
