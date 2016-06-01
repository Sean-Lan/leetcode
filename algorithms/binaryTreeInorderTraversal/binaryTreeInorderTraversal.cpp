/**
 *
 * Sean
 * 2016-06-01
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *  return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Use stack to mock the recursion.
class Solution {
public:
    // recursive version
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        inorderTraversal(root, results);
        return results;
    }

    void inorderTraversal(TreeNode* root, vector<int> &results) {
        if (!root) return;
        inorderTraversal(root->left, results);
        results.push_back(root->val);
        inorderTraversal(root->right, results);
    }

    // iterative version
    vector<int> inorderTraversal2(TreeNode* root) {
        stack<TreeNode *> aStack;
        vector<int> results;

        TreeNode *p = root;
        while (true) {
            while (p) {
                aStack.push(p);
                p = p->left;
            }
            if (aStack.empty()) break;
            p = aStack.top();
            aStack.pop();
            results.push_back(p->val);
            p = p->right;
        }
        return results;
    }

};

int main() {}
