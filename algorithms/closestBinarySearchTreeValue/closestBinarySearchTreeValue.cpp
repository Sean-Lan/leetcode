/**
 *
 * Sean
 * 2017-06-11
 *
 * https://leetcode.com/problems/closest-binary-search-tree-value/#/description
 *
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 *
 * Note:
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest to the target.
 *
 */
#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// the closest value can only be:
//  1. the root val
//  2. in one of the subtree according to ordering compared with the root val
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        auto child = root->val > target ? root->left : root->right;
        if (!child) return root->val;
        int closest = closestValue(child, target);
        return abs(root->val-target) > abs(closest-target) ? closest : root->val;
    }
};

int main() {
    return 0;
}
