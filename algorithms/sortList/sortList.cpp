/**
 *
 * Sean-Lan
 * 2016-08-16
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// merge sort.
class Solution {
private:
    ListNode *merge(ListNode *in1, ListNode *in2) {
        ListNode *p;
        ListNode fakeHead(0);
        ListNode *out = &fakeHead;
        while (in1 && in2) {
            if (in1->val <= in2->val) {
                p = in1;
                in1 = in1->next;
            }
            else {
                p = in2;
                in2 = in2->next;
            }
            out->next = p;
            out = p;
        }
        
        while (in1) {
            out->next = in1;
            out = in1;
            in1 = in1->next;
        }
        
        while (in2) {
            out->next = in2;
            out = in2;
            in2 = in2->next;
        }
        out->next = NULL;
        return fakeHead.next;
    }
    
public:
    ListNode *sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p1, *p2;
        p1 = p2 = head;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        // p1 points to the mid of the list
        p2 = p1->next;
        p1->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(p2);
        return merge(l1, l2);
    }
    
};

ListNode *constructListFromVector(vector<int> &iVec) {
    ListNode fakeHead(0);
    ListNode *p = &fakeHead;
    for (int i : iVec) {
        p->next = new ListNode(i);
        p = p->next;
    }
    return fakeHead.next;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> iVec = {3,1,2};
    ListNode *head = constructListFromVector(iVec);
    printList(head);
    Solution solution;
    head = solution.sortList(head);
    printList(head);
}

