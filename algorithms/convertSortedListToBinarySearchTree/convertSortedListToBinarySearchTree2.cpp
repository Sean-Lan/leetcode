/**
 *
 * Sean
 * 2016-06-15
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 *
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Using two pointers to find the mid of the list.
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;

        ListNode *pp = head;
        ListNode *p = head;
        ListNode *q = head->next;
        while (p && q && q->next) {
            pp = p;
            p = p->next;
            q = q->next->next;
        }

        // p points to the mid node
        TreeNode *root = new TreeNode(p->val);
        if (p == head)
            root->left = nullptr;
        else {
            pp->next = nullptr;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(p->next);
        return root;
    }
};

int main() {}
