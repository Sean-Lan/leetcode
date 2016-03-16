/**
 *
 * Sean
 * 2016-03-16
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 *
 * First find the min length of the two lists, advance the head of the longer until both of the lists have the same length.
 * Then, advance the heads of the two lists at the same time to find the first common node.
 *
 */
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (!headA || !headB) return nullptr;
            int lenA = 0, lenB = 0;
            ListNode *p = headA;
            while (p) {
                ++lenA;
                p = p->next;
            }

            p = headB;
            while (p) {
                ++lenB;
                p = p->next;
            }
            int minLen = min(lenA, lenB);
            int diff;
            if (minLen < lenA) {
                diff = lenA-minLen;
                while (diff--) headA = headA->next;
            }

            if (minLen < lenB) {
                diff = lenB - minLen ;
                while (diff--) headB = headB->next;
            }

            p = nullptr;
            while (headA) {
                if (headA == headB) {
                    p = headA;
                    break;
                }
                headA = headA->next;
                headB = headB->next;
            }
            return p;
        }
};

void printList (ListNode *root) {
    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main() {
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);

    one->next = two;
    two->next = three;
    printList(one);

    ListNode *four = new ListNode(4);
    four->next = two;

    Solution solution;
    ListNode *ret = solution.getIntersectionNode(one, four);
    cout << ret->val << endl;
}
