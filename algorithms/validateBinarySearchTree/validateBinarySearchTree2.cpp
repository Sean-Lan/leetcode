/**
 *
 * Sean
 * 2020-04-23
 *
 * https://leetcode.com/problems/validate-binary-search-tree/
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 */
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// check whether the in-order traversion is sorted.
class Solution {
  // the reason to use hasLower and hasUpper is that some value may equal to INT_MIN or INT_MAX.
  bool helper(TreeNode *root, int lower, bool hasLower, int upper, bool hasUpper) {
    if (!root) return true;
    if (hasLower && root->val <= lower) return false;
    if (hasUpper && root->val >= upper) return false;
    if (!helper(root->left, lower, hasLower, root->val, true)) return false;
    if (!helper(root->right, root->val, true, upper, hasUpper)) return false;

    return true;
  }
  public:
  bool isValidBST(TreeNode* root) {
    return helper(root, INT_MIN, false, INT_MAX, false);
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(1);
  root->left = left;

  Solution s;
  cout << s.isValidBST(root) << endl;
}
