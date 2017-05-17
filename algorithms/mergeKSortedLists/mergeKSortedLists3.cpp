/**
 *
 * Sean
 * 2017-05-17
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/#/description
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 */
#include <queue>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// n: number of lists
// m: number of list nodes
// O(m * log(n))
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode fakeHead(0);
        auto cmp = [](ListNode *p1, ListNode *p2) {
            return p1->val > p2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> aQueue(cmp);
        for (auto &p : lists) {
            if (p) aQueue.push(p);
        }
        ListNode *cur = &fakeHead;
        while (!aQueue.empty()) {
            ListNode *p = aQueue.top();
            cur->next = new ListNode(p->val);
            cur = cur->next;
            if (p->next)
                aQueue.push(p->next);
            aQueue.pop();
        }
        return fakeHead.next;
    }
};

int main() {
    return 0;
}
