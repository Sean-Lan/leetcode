/**
 *
 * Sean
 * 2019-10-22
 *
 * https://leetcode.com/problems/range-sum-of-bst/
 *
 * Given the root node of a binary search tree, return the sum of values of all nodes with value
 * between L and R (inclusive).
 *
 * The binary search tree is guaranteed to have unique values.
 *
 * Example 1:
 *
 * Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
 * Output: 32
 * Example 2:
 *
 * Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 * Output: 23
 *
 *
 * Note:
 *
 * The number of nodes in the tree is at most 10000.
 * The final answer is guaranteed to be less than 2^31.
 *
 */
#include <cstddef>
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
    // recursive
    int rangeSumBST_recursive(TreeNode* root, int L, int R) {
        if (!root) return 0;
        if (root->val < L) {
            return rangeSumBST(root->right, L, R);
        }
        if (root->val > R) {
            return rangeSumBST(root->left, L, R);
        }
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }

    // iterative
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode *> aStack;
        aStack.push(root);

        int res = 0;
        while (!aStack.empty()) {
            TreeNode* cur = aStack.top();
            aStack.pop();
            if (!cur) continue;

            if (cur->val >= L && cur->val <= R) {
                res += cur->val;
                aStack.push(cur->left);
                aStack.push(cur->right);
            } else if (cur->val < L) {
                aStack.push(cur->right);
            } else { // cur->val > R
                aStack.push(cur->left);
            }
        }
        return res;
    }
};
