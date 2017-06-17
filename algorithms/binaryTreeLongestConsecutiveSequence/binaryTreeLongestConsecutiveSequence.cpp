/**
 *
 * Sean
 * 2017-06-17
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/#/solutions
 *
 * Given a binary tree, find the length of the longest consecutive sequence path.
 *
 * The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
 *
 * For example,
 *    1
 *     \
 *      3
 *     / \
 *    2   4
 *         \
 *          5
 * Longest consecutive sequence path is 3-4-5, so return 3.
 *    2
 *     \
 *      3
 *     /
 *    2
 *   /
 *  1
 * Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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

// one thing to note:
// whether the left child or right child is consecutive, we need visit both
// because we want the *global* longest value
class Solution {
    int helper(TreeNode *root, int &longest) {
        if (!root) return 0;
        int res = 1;

        int leftLongest;
        if (root->left) {
            leftLongest = helper(root->left, longest);
            if (root->left->val == root->val+1) {
                res += leftLongest;
            }
        }


        int rightLongest;
        if (root->right) {
            rightLongest = helper(root->right, longest);
            if (root->right->val == root->val+1) {
                res = max(res, rightLongest+1);
            }
        }


        longest = max(longest, res);
        return res;
    }

public:
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        helper(root, longest);
        return longest;
    }
};
