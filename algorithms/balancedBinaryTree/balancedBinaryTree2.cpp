/**
 *
 * Sean
 * 2016-03-27
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the
 * depth of the two subtrees of every node never differ by more than 1.
 *
 */
#include <iostream>
#include <cstdlib>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// DFS
class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if (!root) return true;
            int leftHeight = maxHeight(root->left);
            int rightHeight = maxHeight(root->right);
            return std::abs(leftHeight-rightHeight)<2 && isBalanced(root->left) &&
                isBalanced(root->right);
        }

    private:
        int maxHeight(TreeNode *root) {
            if (!root) return 0;
            return max(maxHeight(root->left), maxHeight(root->right))+1;
        }
};

int main() {}
