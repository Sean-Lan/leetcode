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

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (!head) return NULL;
            ListNode fakeHead(0);
            fakeHead.next = head;
            ListNode *lastEnd = &fakeHead;
            ListNode *nextBeg;
            // reverse every k nodes.
            do {
                nextBeg = lastEnd->next;
                auto range = reverseList(nextBeg, k);
                lastEnd->next = range.first;
                lastEnd = range.second;
            } while (lastEnd);
            return fakeHead.next;
        }

    private:
        /**
         * First check whether there is enough k nodes from head.
         * If there is enough, then reverse k nodes from head.
         * Return a range represents the reversed list.
         */
        pair<ListNode*,ListNode *> reverseList(ListNode *head, int k) {
            if (!head) return {NULL, NULL};
            ListNode *p1 = head;
            ListNode *p2 = p1->next;
            // first check
            int i=1;
            for (; i<k && p2; ++i, p2=p2->next);
            if (i<k) return {head, NULL};

            // then reverse
            p2 = p1->next;
            i = 1;
            for (; i<k; ++i) {
                p1->next = p2->next;
                p2->next = head;
                head = p2;
                p2 = p1->next;
            }
            return {head, p1};
        }
};

void printList(ListNode *head) {
    if (head) {
        cout << head->val;
        head = head->next;
    }
    while (head) {
        cout << "->" << head->val;
        head = head->next;
    }
    cout << endl;
}

ListNode *constructList(vector<int> values) {
    ListNode fakeHead = ListNode(0);
    ListNode *current = &fakeHead;
    for (auto &val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return fakeHead.next;
}

void deleteList(ListNode *head) {
    if (!head) return;
    ListNode *current = head->next;
    ListNode *tmp;
    while (current) {
        tmp = current;
        current = current->next;
        delete tmp;
    }
}

int main() {
    ListNode *testList = constructList({1,2,3,4,5});
    Solution s;
    printList(testList);
    testList = s.reverseKGroup(testList, 6);
    printList(testList);
    deleteList(testList);
}
