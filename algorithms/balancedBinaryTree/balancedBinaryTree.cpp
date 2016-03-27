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
#include <iostream>
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
            bool balanced = true;
            maxHeight(root, balanced);
            return balanced;
        }

    private:
        int maxHeight(TreeNode *root, bool &balanced) {
            if (!balanced) return -1;
            if (!root) return 0;
            int leftMax = maxHeight(root->left, balanced);
            int rightMax = maxHeight(root->right, balanced);
            int height = max(leftMax, rightMax);
            if (height-leftMax>1 || height-rightMax>1) balanced = false;
            return height+1;
        }
};

int main() {}
