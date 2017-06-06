/**
 *
 * Sean
 * 2017-06-06
 *
 * https://leetcode.com/problems/count-univalue-subtrees/#/description
 *
 * Given a binary tree, count the number of uni-value subtrees.
 *
 * A Uni-value subtree means all nodes of the subtree have the same value.
 *
 * For example:
 * Given binary tree,
 *               5
 *              / \
 *             1   5
 *            / \   \
 *           5   5   5
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

// DFS.
// Recusively check whether left and right subtree is univalue
class Solution {
    bool helper(TreeNode *root, int &cnt) {
        bool leftUni, rightUni;
        leftUni = rightUni = true;

        if (root->left)
           leftUni = helper(root->left, cnt);

        if (root->right)
            rightUni = helper(root->right, cnt);

        if (!leftUni || !rightUni) return false;

        int val = root->val;

        if (root->left)
            leftUni = root->left->val == val;

        if (root->right)
            rightUni = root->right->val == val;

        if (leftUni && rightUni) {
            ++ cnt;
            return true;
        }

        return false;
    }

public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        int cnt = 0;
        helper(root, cnt);
        return cnt;
    }
};

int main() {
    return 0;
}
