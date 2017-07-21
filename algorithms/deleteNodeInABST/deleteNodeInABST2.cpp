/**
 *
 * Sean
 * 2017-07-21
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

// recurisve solution
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else { // root->val == key
            TreeNode *pr = root->right;
            if (!pr) {
                TreeNode *pl = root->left;
                delete root;
                root = pl;
            } else {
                TreeNode *pl = pr->left;
                if (!pl) {
                    swap(root->val, pr->val);
                } else {
                    while (pl->left) {
                        pl = pl->left;
                    }
                    swap(root->val, pl->val);
                }
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};

int main() {
    return 0;
}
