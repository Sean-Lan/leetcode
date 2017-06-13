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
#include <stack>
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode *> aStack;
        // push the nodes with value >= p->val into a stack and turn left/right according to the order
        while (root) {
            if (root->val > p->val) {
                aStack.push(root);
                root = root->left;
            } else if (root == p) {
                aStack.push(root);
                break;
            } else {
                root = root->right;
            }
        }

        // push into stack the left most node of the p's right child if it exists
        // the stop of the stack is the successor of p
        auto cur = aStack.top();
        aStack.pop();
        cur = cur->right;
        while (cur) {
            aStack.push(cur);
            cur = cur->left;
        }

        if (aStack.empty()) return nullptr;
        return aStack.top();
    }
};

int main() {
    return 0;
}
