/**
 *
 * Sean
 * 2017-06-17
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/#/description
 *
 * Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
 *
 * Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
 *
 * Example 1:
 * Input:
 *         1
 *        / \
 *       2   3
 * Output: 2
 * Explanation: The longest consecutive path is [1, 2] or [2, 1].
 * Example 2:
 * Input:
 *         2
 *        / \
 *       1   3
 * Output: 3
 * Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 * Note: All the values of tree nodes are in the range of [-1e7, 1e7].
 *
 * Show Company Tags
 * Show Tags
 * Show Similar Problems
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

class Solution {
    pair<int, int> helper(TreeNode *root, int &longest) {
        if (!root) return {0, 0};

        int rootIncr = 1; // longest increasing consecutive length starting from root
        int rootDecr = 1; // longest decreasing consecutive length starting from root
        if (root->left) {
            auto res = helper(root->left, longest);
            if (root->left->val+1 == root->val) {
                rootDecr += res.second;
            }
            if (root->left->val == root->val+1) {
                rootIncr += res.first;
            }
        }

        if (root->right) {
            auto res = helper(root->right, longest);
            if (root->right->val+1 == root->val) {
                rootDecr = max(rootDecr, res.second+1);
            }
            if (root->right->val == root->val+1) {
                rootIncr = max(rootIncr, res.first+1);
            }
        }

        longest = max(longest, rootIncr + rootDecr - 1);
        return {rootIncr, rootDecr};
    }
public:
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        helper(root, longest);
        return longest;
    }
};

int main() {
    return 0;
}
