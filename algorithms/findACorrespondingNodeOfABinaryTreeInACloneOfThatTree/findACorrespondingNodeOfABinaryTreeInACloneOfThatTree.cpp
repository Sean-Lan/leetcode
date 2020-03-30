/**
 *
 * Sean
 * 2020-03-30
 *
 * https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 *
 * Given two binary trees original and cloned and given a reference to a node target in the original
 * tree.
 *
 * The cloned tree is a copy of the original tree.
 *
 * Return a reference to the same node in the cloned tree.
 *
 * Note that you are not allowed to change any of the two trees or the target node and the answer
 * must be a reference to a node in the cloned tree.
 *
 * Follow up: Solve the problem if repeated values on the tree are allowed.
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
  TreeNode* tranverse(TreeNode* curOriginal, TreeNode* curCloned, TreeNode* target) {
    if (!curOriginal) return nullptr;
    if (curOriginal == target) return curCloned;
    TreeNode * ret = nullptr;

    // left
    ret = tranverse(curOriginal -> left, curCloned -> left, target);
    if (ret) return ret;

    // right
    ret = tranverse(curOriginal -> right, curCloned -> right, target);
    return ret;
  }
  public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    return tranverse(original, cloned, target);
  }
};

int main() {
  return 0;
}
