/**
 *
 * Sean
 * 2016-11-27
 *
 * https://leetcode.com/problems/find-leaves-of-binary-tree/
 *
 * Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
 *
 * Example:
 * Given binary tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Returns [4, 5, 3], [2], [1].
 *
 * Explanation:
 * 1. Removing the leaves [4, 5, 3] would result in this tree:
 *
 *           1
 *          /
 *         2
 *
 * 2. Now removing the leaf [2] would result in this tree:
 *
 *           1
 *
 * 3. Now removing the leaf [1] would result in the empty tree:
 *
 *           []
 *
 * Returns [4, 5, 3], [2], [1].
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

// O(n*(log(n))^2)
class Solution {
    bool isLeaf(TreeNode *node) {
        return !node->left && !node->right;
    }

    // Find current level of leaves and remove them from the tree.
    void getLeaves(TreeNode *root, vector<int> &leaves) {
        if (root->left && isLeaf(root->left)) {
            leaves.push_back(root->left->val);
            delete root->left;
            root->left = nullptr;
        }
        if (root->right && isLeaf(root->right)) {
            leaves.push_back(root->right->val);
            delete root->right;
            root->right = nullptr;
        }

        if (root->left) getLeaves(root->left, leaves);
        if (root->right) getLeaves(root->right, leaves);
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> leaves;
        while (!isLeaf(root)) {
            getLeaves(root, leaves);
            res.push_back(leaves);
            leaves.clear();
        }
        res.push_back({root->val});
        return res;
    }
};
