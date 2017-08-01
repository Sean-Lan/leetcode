/**
 *
 * Sean
 * 2017-07-31
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * For example:
 * Given BST [1,null,2,2],
 *    1
 *     \
 *      2
 *     /
 *    2
 * return [2].
 *
 * Note: If a tree has more than one mode, you can return them in any order.
 *
 * Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n)
// two pass, one for calculate the show times of the mode, another for collecting all the modes
// take advantage of the increasing order of BST's in-order tranversal
class Solution {
    int cur;
    int curCnt;
    int maxCnt;
    vector<int> modes;
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        curCnt = 0;
        maxCnt = 1;
        inorder(root, false);
        cout << maxCnt << endl;
        curCnt = 0;
        inorder(root, true);
        return modes;
    }

    void inorder(TreeNode *root, bool collecting) {
        if (root->left) inorder(root->left, collecting);

        if (root->val == cur) {
            ++ curCnt;
            if (curCnt > maxCnt) {
                maxCnt = curCnt;
            }
        } else {
            cur = root->val;
            curCnt = 1;
        }
        if (collecting && curCnt == maxCnt) modes.push_back(cur);
        if (root->right) inorder(root->right, collecting);
    }

};

int main() {
    return 0;
}

