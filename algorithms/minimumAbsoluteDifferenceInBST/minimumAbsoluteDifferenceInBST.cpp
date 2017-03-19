/**
 *
 * Sean
 * 2017-03-19
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description
 *
 *
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * Input:
 * 
 *    1
 *     \
 *      3
 *     /
 *    2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 * Note: There are at least two nodes in this BST.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// In-order tranversal
class Solution {
    int helper(TreeNode *root, int &lastVal) {
        int minDiff = INT_MAX;
        if (root->left) minDiff = min(minDiff, helper(root->left, lastVal));
        if (lastVal >= 0) {
            minDiff = min(minDiff, abs(root->val-lastVal));
        }
        lastVal = root->val;

        if (root->right) minDiff = min(minDiff, helper(root->right, lastVal));
        return minDiff;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int lastValue = -1;
        return helper(root, lastValue);
    }
};

int main() {
    return 0;
}
