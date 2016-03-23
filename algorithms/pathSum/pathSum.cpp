/**
 *
 * Sean
 * 2016-03-23
 *
 * https://leetcode.com/problems/path-sum/
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

// use DFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        int current = root->val;
        return helper(root, current, sum);
    }
private:
    bool helper(TreeNode *root, int &current, const int &sum) {
        if (!root->left && !root->right) {
            if (current == sum)
                return true;
            else
                return false;
        }

        TreeNode *leftChild = root->left;
        if (leftChild) {
            current += leftChild->val;
            if (helper(leftChild, current, sum)) return true;
            current -= leftChild->val;
        }

        TreeNode *rightChild = root->right;
        if (rightChild) {
            current += rightChild->val;
            if (helper(rightChild, current, sum)) return true;
            current -= rightChild->val;
        }
        return false;
    }
};

int main() {}
