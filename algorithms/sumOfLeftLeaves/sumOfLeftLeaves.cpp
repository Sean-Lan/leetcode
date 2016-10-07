/**
 *
 * Sean
 * 2016-10-07
 *
 * https://leetcode.com/problems/sum-of-left-leaves/
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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

class Solution {
    void dfs(TreeNode* root, bool isLeft, int &sum) {
        if (!root) return;
        if (isLeft && !root->left && !root->right) {
            sum += root->val;
        }
        dfs(root->left, true, sum);
        dfs(root->right, false, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        dfs(root, false, total);
        return total;
    }
};

int main() {}
