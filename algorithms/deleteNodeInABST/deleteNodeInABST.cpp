/**
 *
 * Sean
 * 2017-07-19
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/#/description
 *
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 *
 * Basically, the deletion can be divided into two stages:
 *
 * Search for a node to remove.
 * If the node is found, delete the node.
 * Note: Time complexity should be O(height of tree).
 *
 * Example:
 *
 * root = [5,3,6,2,4,null,7]
 * key = 3
 *
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 *
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 *
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 *
 *     5
 *    / \
 *   4   6
 *  /     \
 * 2       7
 *
 * Another valid answer is [5,2,6,null,4,null,7].
 *
 *     5
 *    / \
 *   2   6
 *    \   \
 *     4   7
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

// iterative solution
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *p = root;
        TreeNode *pp = nullptr;
        while (p) {
            if (p->val == key) break;
            pp = p;
            p = (p->val > key) ? p->left : p->right;
        }
        if (!p) return root;

        TreeNode *pr = p->right;
        if (pr) {
            // find the TreeNode with minimum value
            TreeNode *ppr = nullptr;
            while (pr->left) {
                ppr = pr;
                pr = pr->left;
            }
            if (ppr) {
                ppr->left = pr->right;
                pr->right = p->right;
            }
            pr->left = p->left;
            if (!pp) {
                root = pr;
            } else if (pp->left == p) {
                pp->left = pr;
            } else {
                pp->right = pr;
            }
        } else {
            if (!pp) {
                root = p->left;
            } else if (pp->left == p) {
                pp->left = p->left;
            } else {
                pp->right = p->left;
            }
        }
        delete p;
        return root;
    }
};

int main() {
    return 0;
}
