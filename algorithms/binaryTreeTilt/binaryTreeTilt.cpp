/**
 *
 * Sean
 * 2017-04-26
 *
 * https://leetcode.com/problems/binary-tree-tilt/#/description
 *
 * Given a binary tree, return the tilt of the whole tree.
 *
 * The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 *
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 *
 * Example:
 *
 * Input:
 *          1
 *        /   \
 *       2     3
 *
 * Output: 1
 * Explanation:
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 * Note:
 *
 * The sum of node values in any subtree won't exceed the range of 32-bit integer.
 * All the tilt values won't exceed the range of 32-bit integer.
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

// O(n)
// Post-order tranversal
class Solution {
    int tiltSum = 0;
    int getSum(TreeNode *root) {
        if (!root) return 0;
        int leftSum = getSum(root->left);
        int rightSum = getSum(root->right);
        tiltSum += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        getSum(root);
        return tiltSum;
    }
};

int main() {
    return 0;
}
