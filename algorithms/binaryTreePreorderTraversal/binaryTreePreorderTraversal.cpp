/**
 *
 * Sean
 * 2016-07-28
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [1,2,3].
 *
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Use a stack to store the right child when traverse from the root.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode *> aStack;
        aStack.push(root);
        while (!aStack.empty()) {
            root = aStack.top();
            aStack.pop();
            while (root) {
                res.push_back(root->val);
                if (root->right) aStack.push(root->right);
                root = root->left;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
