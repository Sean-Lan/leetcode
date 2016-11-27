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
 * 2. Now removing the leaf [2] would result in this tree:
 *
 *           1
 * 3. Now removing the leaf [1] would result in the empty tree:
 *
 *           []
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

class Solution {
    // return the height of the node, and the height of leaf node is 0
    int getHeight(TreeNode *root, vector<vector<int>> &res) {
        if (!root) return -1;
        int height = 1 + max(getHeight(root->left, res), getHeight(root->right, res));
        if (height == res.size()) {
            res.push_back({root->val});
        } else {
            res[height].push_back(root->val);
        }
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        getHeight(root, res);
        return res;
    }
};
