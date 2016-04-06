/**
 *
 * Sean
 * 2016-04-06
 *
 * https://leetcode.com/problems/symmetric-tree/
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 *
 */
#include <iostream>
#include <stack>
#include <utility>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// use a stack to mock the recursion.
class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (!root) return true;
            stack<pair<TreeNode*, TreeNode*>> aStack;
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            if (!left && !right) return true;
            if ((!left && right) || (left && !right)) return false;
            while (true) {
                while (left && right) {
                    if (left->val != right->val) return false;
                    aStack.push(make_pair(left, right));
                    left = left->left;
                    right = right->right;
                }
                if (left || right) return false;
                if (aStack.empty()) break;
                auto aPair = aStack.top();
                aStack.pop();
                left = aPair.first->right;
                right = aPair.second->left;
            };
            return true;
        }
};

int main() {
}
