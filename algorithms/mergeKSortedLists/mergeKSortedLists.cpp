/**
 *
 * Sean
 * 2016-02-02
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 */
#include <vector>
#include <cstddef>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 *
 * The naive method to sovle this problem is to use mergeTwoLists to merge the lists from left to right.
 * However, when the lists is skewed, i.e, one list is too long, while others are short, the complexity is
 * O(maxLength * sizeof(lists)), which is too high.
 *
 * Use divide and conquer, separate the lists into two half, and merge them separately. The complexity can
 * be reduced to O(maxLength * log(sizeof(lists)), which is acceptable.
 *
 */

class Solution {
    private:
        typedef vector<ListNode *>::iterator It;
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.empty()) return NULL;
            if (lists.size() == 1) return lists[0];
            if (lists.size() == 2)
                return mergeTwoLists(lists[0], lists[1]);

            int mid = lists.size()/2;
            auto firstHalf = vector<ListNode *>(lists.begin(), lists.begin()+mid);
            auto secondHalf = vector<ListNode *>(lists.begin()+mid, lists.end());
            ListNode *list1 = mergeKLists(firstHalf);
            ListNode *list2 = mergeKLists(secondHalf);
            return mergeTwoLists(list1, list2);
        }

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (!l1) return l2;
            if (!l2) return l1;
            ListNode *p1 = l1;
            ListNode *p2 = l2;
            ListNode fakeHead = ListNode(0);
            ListNode *head = &fakeHead; // fake head
            ListNode *pCur = head;
            while (p1 && p2) {
                if (p1->val < p2->val) {
                    pCur->next = p1;
                    p1 = p1->next;
                } else {
                    pCur->next = p2;
                    p2 = p2->next;
                }
                pCur = pCur->next;
            }

            // copy the remaining
            if (p1) pCur->next = p1;
            if (p2) pCur->next = p2;
            return head->next;
        }
};
