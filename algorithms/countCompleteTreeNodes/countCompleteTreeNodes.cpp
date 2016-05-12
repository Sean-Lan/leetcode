/**
 *
 * Sean
 * 2016-05-12
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/
 *
 * Given a complete binary tree, count the number of nodes.
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled,
 * and all nodes in the last level are as far left as possible.
 * It can have between 1 and 2h nodes inclusive at the last level h.
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

// O(log(n)^2) solution.
// Compare the left-most depth and right-most depth of a tree to check whether it is full.
// Either left sub-tree or right sub-tree is not full.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int cnt = 1;
        int leftDepth = depth(root->left, true);
        int rightDepth = depth(root->left, false);
        if (leftDepth == rightDepth) { // the left sub-tree is full
            cnt += (1<<leftDepth) - 1;
            cnt += countNodes(root->right);
        } else { // the right sub-tree is full
            --leftDepth;
            cnt += (1<<leftDepth) - 1;
            cnt += countNodes(root->left);
        }
        return cnt;
    }

private:
    int depth(TreeNode *root, bool toLeft) {
        int cnt = 0;
        if (toLeft) {
            while (root) {
                ++cnt;
                root = root->left;
            }
        } else {
            while (root) {
                ++cnt;
                root = root->right;
            }
        }
        return cnt;
    }
};

int main() {}
