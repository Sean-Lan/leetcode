/**
 *
 * Sean
 * 2016-12-16
 *
 * https://leetcode.com/problems/binary-tree-upside-down/
 *
 * Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
 *
 * For example:
 *
 * Given a binary tree {1,2,3,4,5},
 *
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 *
 * return the root of the binary tree [4,5,2,#,#,3,1].
 *
 *    4
 *   / \
 *  5   2
 *     / \
 *    3   1
 *
 */
#include <iostream>
#include <stack>
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        stack<TreeNode *> rootStack;
        stack<TreeNode *> rightStack;
        while (root) {
            rootStack.push(root);
            rightStack.push(root->right);
            root = root->left;
        }
        root = rootStack.top();
        rootStack.pop();
        rightStack.pop();
        TreeNode *last = root;
        while (!rootStack.empty()) {
            last->right = rootStack.top();
            rootStack.pop();
            last->left = rightStack.top();
            rightStack.pop();
            last = last->right;
        }
        // important! clear the right most node's two child pointers,
        // otherwise the returned tree is a infinite loop itself.
        last->left = last->right = nullptr;
        return root;
    }
};

int main() {
    TreeNode one = TreeNode(1);
    TreeNode two = TreeNode(2);
    one.left = &two;
    Solution solution;
    TreeNode *root = solution.upsideDownBinaryTree(&one);
    cout << root->val << " " << root->right->val << endl;
    return 0;
}
