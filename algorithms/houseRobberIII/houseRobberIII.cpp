/**
 *
 * Sean
 * 2017-05-26
 *
 * https://leetcode.com/problems/house-robber-iii/#/description
 *
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 *
 * Example 1:
 *      3
 *     / \
 *    2   3
 *     \   \
 *      3   1
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  1   3   1
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 */
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// top-down DP
class Solution {
    unordered_map<TreeNode *, int> robMax, skipMax;
    int rob(TreeNode *root, bool robRoot) {
        if (!root) return 0;
        int maxValue = 0;
        if (robRoot) {
            if (robMax.count(root)) return robMax[root];
            int maxLeft = rob(root->left, false);
            int maxRight = rob(root->right, false);
            maxValue = maxLeft + maxRight + root->val;
            robMax[root] = maxValue;
        } else {
            if (skipMax.count(root)) return skipMax[root];
            int maxLeft = max(rob(root->left, true), rob(root->left, false));
            int maxRight = max(rob(root->right, true), rob(root->right, false));
            maxValue = maxLeft + maxRight;
            skipMax[root] = maxValue;
        }
        return maxValue;
    }

public:
    int rob(TreeNode* root) {
        robMax.clear();
        skipMax.clear();
        return max(rob(root, true), rob(root, false));
    }
};

int main() {
    return 0;
}
