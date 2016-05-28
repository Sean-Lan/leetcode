/**
 *
 * Sean
 * 2016-05-28
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
        void flatten(TreeNode* root) {
            helper(root);
        }

        // return the pointer to last node in pre-order tranversal.
        TreeNode* helper(TreeNode *root) {
            if (!root) return NULL;
            auto leftLast = helper(root->left);
            auto rightLast = helper(root->right);
            if (leftLast) {
                leftLast->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            if (rightLast)
                return rightLast;
            if (leftLast)
                return leftLast;
            return root;
        }
};

void printList(TreeNode *root) {
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
}
int main() {
    TreeNode one(1), two(2), three(3);
    one.left = &two;
    two.left = &three;

    Solution solution;
    solution.flatten(&one);
    printList(&one);
}
