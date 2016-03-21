/**
 *
 * Sean
 * 2016-03-21
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/
 *
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node
 * in the tree along the parent-child connections. The path does not need to go through the root.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 * Return 6.
 *
 */
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// `oneWayMax` means the max sum of `root->val` and one of its child path.
// `globalMax` is the global max path sum.
// Each recursion obtain a new `globalMax` as:
//    globalMax = max(globalMax, root->val+leftMax+rightMax);
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = std::numeric_limits<int>::min();
        helper(root, globalMax);
        return globalMax;
    }

    int helper(TreeNode *root, int &globalMax) {
        if (!root) return 0;
        int leftMax = helper(root->left, globalMax);
        int rightMax = helper(root->right, globalMax);
        leftMax = max(0, leftMax);
        rightMax = max(0, rightMax);
        int oneWayMax = max(root->val+leftMax, root->val+rightMax);
        globalMax = max(globalMax, root->val+leftMax+rightMax);
        return oneWayMax;
    }
};

int main() {}
