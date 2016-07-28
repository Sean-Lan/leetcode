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
        vector<int> result;
        if (!root) return result;
        stack<TreeNode *> aStack;
        aStack.push(root);

        TreeNode *cur;
        while (!aStack.empty()) {
            cur = aStack.top();
            aStack.pop();
            result.push_back(cur->val);
            if (cur->right) {
                aStack.push(cur->right);
            }

            while (cur->left) {
                cur = cur->left;
                result.push_back(cur->val);
                if (cur->right)
                    aStack.push(cur->right);
            }
        }

        return result;
    }
};

int main() {
    return 0;
}
