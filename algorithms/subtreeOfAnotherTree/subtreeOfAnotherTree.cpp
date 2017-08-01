/**
 *
 * Sean
 * 2017-08-01
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
 *
 * Example 1:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return true, because t has the same structure and node values with a subtree of s.
 *
 * Example 2:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *     /
 *    0
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return false.
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

// O(m*n) time, O(n) space, where `m` is the number of nodes in `t` and `n` is that in `s`
class Solution {
    // O(m)
    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if ((s && !t) || (!s && t)) return false;
        if (s->val == t->val
            && isSameTree(s->left, t->left)
            && isSameTree(s->right, t->right))
            return true;
        return false;
    }
public:
    // at most called n times
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s || !t) return false;
        if (isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t)) return true;
        return false;
    }
};

int main() {
    return 0;
}
