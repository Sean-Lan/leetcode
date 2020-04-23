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

class Solution {
public:
    // O(n) time and space solution, first inorder tranverse the tree, then find the nodes.
    void recoverTree(TreeNode* root) {
        if (!root) return;
        vector<TreeNode *> pointers;
        vector<TreeNode *> wrongPointers;

        inorderTranversal(root, pointers);

        int size = pointers.size();
        for (int i=0; i<size-1; ++i) {
            if (pointers[i]->val > pointers[i+1]->val) {
                wrongPointers.push_back(pointers[i]);
                wrongPointers.push_back(pointers[i+1]);
            }
        }

        auto aPair = minmax_element(wrongPointers.begin(), wrongPointers.end(),
                    [](TreeNode *& p1, TreeNode *&p2) {
                       return p1->val < p2->val;
                    });

        auto p1 = *aPair.first;
        auto p2 = *aPair.second;
        std::swap(p1->val, p2->val);
    }

    void inorderTranversal(TreeNode *root, vector<TreeNode *> &pointers) {
        if (!root) return;
        inorderTranversal(root->left, pointers);
        pointers.push_back(root);
        inorderTranversal(root->right, pointers);
    }
};

int main() {
    Solution solution;
    TreeNode two(2);
    TreeNode one(1);
    two.right = &one;
    solution.recoverTree(&two);
}
