/**
 *
 * Sean
 * 2017-08-01
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 *
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 * Note: The length of path between two nodes is represented by the number of edges between them.
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

// O(n)
// Just tranverse the tree to get the tree height, and at the same time
// update the max diameter
class Solution {
    int treeHeight(TreeNode *root, int &d) {
        if(!root) return 0;
        int lh = treeHeight(root->left, d);
        int rh = treeHeight(root->right, d);
        d = max(d, lh+rh);
        return max(lh, rh) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        treeHeight(root, d);
        return d;
    }
};

int main() {
    return 0;
}
