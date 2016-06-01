/**
 *
 * Sean
 * 2016-06-01
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
#include <vector>
#include <utility>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// find all node's prev and next node, check if it violates the BST order.
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        vector<TreeNode *> wrongNodes;
        helper(root, nullptr, nullptr, wrongNodes);

        auto aPair = minmax_element(wrongNodes.begin(), wrongNodes.end(),
                        [](TreeNode *&p1, TreeNode *&p2)->bool {
                           return p1->val < p2->val;
                        });
        TreeNode *p1 = *aPair.first;
        TreeNode *p2 = *aPair.second;
        std::swap(p1->val, p2->val);

    }

    void helper(TreeNode *node, TreeNode *defaultPrev, TreeNode *defaultNext, vector<TreeNode *> &wrongNodes) {
        if (!node) return;
        TreeNode *prevNode = prev(node, defaultPrev);
        TreeNode *nextNode = next(node, defaultNext);

        if (!prevNode) {
            if (node->val > nextNode->val)
                wrongNodes.push_back(node);
        } else if (!nextNode) {
            if (prevNode->val > node->val)
                wrongNodes.push_back(node);
        } else {
            if (node->val > nextNode->val ||
                prevNode->val > node->val)
                wrongNodes.push_back(node);
        }

        helper(node->left, defaultPrev, node, wrongNodes);
        helper(node->right, node, defaultNext, wrongNodes);
    }

    TreeNode *prev(TreeNode *node, TreeNode *defaultNode) {
        if (!node || !node->left) return defaultNode;
        TreeNode *p = node->left;
        while (p->right) {
            p = p->right;
        }
        return p;
    }

    TreeNode *next(TreeNode *node, TreeNode *defaultNode) {
        if (!node || !node->right) return defaultNode;
        TreeNode *p = node->right;
        while(p->left) {
            p = p->left;
        }
        return p;
    }
};

int main() {
    Solution solution;
    TreeNode two(2);
    TreeNode one(1);
    two.right = &one;
    solution.recoverTree(&two);
}
