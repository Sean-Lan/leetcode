/**
 *
 * Sean
 * 2020-04-23
 *
 * https://leetcode.com/problems/recover-binary-search-tree/
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 *
 */
#include <iostream>
#include <set>
#include <utility>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// O(n) time and const addition space solution
// just compare the current node with the previous one.
// the smaller out-of-order one is the first one of the out-of-order pair
// the bigger out-of-order one may change twice
class Solution {
  TreeNode* inOrder(TreeNode *root, TreeNode *passedInPrev, TreeNode *&p1, TreeNode *&p2) {
    if (!root) return nullptr;
    TreeNode *prev = passedInPrev;
    if (root->left) {
      prev = inOrder(root->left, passedInPrev, p1, p2);
    }
    if (prev && root->val < prev->val) {
      if (!p1) p1 = prev;
      p2 = root;
    }
    if (root->right) {
      return inOrder(root->right, root, p1, p2);
    }
    return root;
  }

  public:
  void recoverTree(TreeNode* root) {
    TreeNode *p1 = nullptr;
    TreeNode *p2 = nullptr;
    inOrder(root, nullptr, p1, p2);

    swap(p1->val, p2->val);
  }
};

int main() {
  return 0;
}
