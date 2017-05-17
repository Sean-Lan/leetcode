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
#include <iostream>
#include <vector>
#include <set>
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
            return p1->val < p2->val;
        };
        // use `multiset` since the numbers may be the same
        multiset<ListNode *, decltype(cmp)> aSet(cmp);
        for (auto &p : lists) {
            if (p) aSet.insert(p);
        }
        ListNode *cur = &fakeHead;
        while (!aSet.empty()) {
            auto it = aSet.begin();
            ListNode *p = *it;
            cur->next = new ListNode(p->val);
            cur = cur->next;
            if (p->next)
                aSet.insert(p->next);
            aSet.erase(it);
        }
        return fakeHead.next;
    }
};

int main() {
    return 0;
}
