/**
 *
 * Sean
 * 2016-05-28
 *
 * https://leetcode.com/problems/same-tree/
 *
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 *
 */
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p) {
            if (q) return false;
            return true;
        }
        if (!q) {
            if (p) return false;
            return true;
        }

        if (p->val != q->val) return false;

        if (isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right))
            return true;
        return false;
    }
};

int main() {}
