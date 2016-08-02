/**
 *
 * Sean
 * 2016-08-03
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [3,2,1].
 *
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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        // pointer to a node and its right child
        stack<pair<TreeNode *, TreeNode*> >aStack;
        TreeNode *cur = root;
        
        // initialize the stack
        while (cur) {
            aStack.push(make_pair(cur, cur->right));
            cur = cur->left;
        }
        
        while (!aStack.empty()) {
            auto &aPair = aStack.top();
            if (!aPair.second) { // all left and right child tree has been visited
                result.push_back(aPair.first->val);
                aStack.pop();
            } else {
                cur = aPair.second; // begin visit the right child tree
                while (cur) {
                    aPair.second = nullptr; // mark that the right child tree is visited
                    aStack.push(make_pair(cur, cur->right));
                    cur = cur->left;
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
