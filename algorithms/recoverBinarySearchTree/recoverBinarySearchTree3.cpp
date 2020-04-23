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

class Comp {
  public:
    bool operator()(TreeNode * p1, TreeNode * p2) const {
      return p1->val < p2->val;
    }
};

// O(n) time and const addition space solution
// just compare the current node with the previous one.
// the out-of-order ones must the be smallest and largest
class Solution {
  TreeNode* inOrder(TreeNode *root, TreeNode *passedInPrev, set<TreeNode *, Comp> &wrongNodes) {
    if (!root) return nullptr;
    TreeNode *prev = passedInPrev;
    if (root->left) {
      prev = inOrder(root->left, passedInPrev, wrongNodes);
    }
    if (prev && root->val < prev->val) {
      wrongNodes.insert(prev);
      wrongNodes.insert(root);
    }
    if (root->right) {
      return inOrder(root->right, root, wrongNodes);
    }
    return root;
  }

  public:
  void recoverTree(TreeNode* root) {
    set<TreeNode *, Comp> wrongNodes;
    inOrder(root, nullptr, wrongNodes);

    TreeNode *p1 = *wrongNodes.begin();
    TreeNode *p2 = *wrongNodes.rbegin();
    swap(p1->val, p2->val);
  }
};

int main() {
  return 0;
}
