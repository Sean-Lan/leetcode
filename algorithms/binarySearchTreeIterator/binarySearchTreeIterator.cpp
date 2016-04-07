/**
 *
 * Sean
 * 2016-04-07
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 *
 */
#include <iostream>
#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// use a stack to store the nodes to be visited.
class BSTIterator {
    public:
        BSTIterator(TreeNode *root) {
            while (root) {
                aStack.push(root);
                root=root->left;
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !aStack.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode *p = aStack.top();
            int val = p->val;
            aStack.pop();
            p = p->right;
            while (p) {
                aStack.push(p);
                p=p->left;
            }
            return val;
        }

    private:
        stack<TreeNode*> aStack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {}
