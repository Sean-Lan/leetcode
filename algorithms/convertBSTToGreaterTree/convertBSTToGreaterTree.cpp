/**
 *
 * Sean
 * 2017-07-16
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/#/description
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
 *
 *               5
 *             /   \
 *            2     13
 *
 * Output: The root of a Greater Tree like this:
 *
 *              18
 *             /   \
 *           20     13
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

// first visit the right child, then root, then left
// use sum to store the cumlative sum to the right, which the
// sum of numbers large than current value
class Solution {
    int visit(TreeNode *root, int sum) {
        if (!root) return sum;
        root->val += visit(root->right, sum);
        return visit(root->left, root->val);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        visit(root, 0);
        return root;
    }
};

int main() {
    return 0;
}
