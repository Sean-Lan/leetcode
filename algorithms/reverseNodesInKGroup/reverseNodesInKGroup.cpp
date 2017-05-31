/**
 *
 * Sean
 * 2016-02-03
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 *
 */
#include <cstddef>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // p1 -> x -> ... -> p2 -> y -> ... =>
    // p1 -> y -> x -> ... -> p2 -> ...
    void shift(ListNode *p1, ListNode *p2) {
        ListNode *tmp1, *tmp2;
        tmp1 = p1->next; // x
        tmp2 = p2->next; // y
        p1->next = tmp2;
        p2->next = tmp2->next;
        tmp2->next = tmp1;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode *preCur = &fakeHead;
        ListNode *cur = fakeHead.next;
        ListNode *tmp;

        do {
            int i;
            tmp = cur;
            for (i=0; i<k; ++i) {
                if (!tmp) break;
                tmp = tmp->next;
            }
            if (i != k) break; // < k nodes remained

            // reverse the k nodes [cur, tmp]
            for (i=1; i<k; ++i) { // only need k-1 times shift
                shift(preCur, cur);
            }
            preCur = cur;
            cur = preCur->next;
        } while (cur);

        return fakeHead.next;
    }
};

int main() {
    return 0;
}
