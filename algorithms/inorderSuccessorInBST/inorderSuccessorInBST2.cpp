/**
 *
 * Sean
 * 2017-06-13
 *
 * https://leetcode.com/problems/inorder-successor-in-bst/#/description
 *
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 *
 * Note: If the given node has no in-order successor in the tree, return null.
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


// recursive solution
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return nullptr;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        }
        auto cur = inorderSuccessor(root->left, p);
        return cur ? cur : root;
    }
};

int main() {
    return 0;
}
