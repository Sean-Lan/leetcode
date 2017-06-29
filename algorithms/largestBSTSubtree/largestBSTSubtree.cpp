/**
 *
 * Sean
 * 2017-06-29
 *
 * https://leetcode.com/problems/largest-bst-subtree/#/description
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
 *
 * Note:
 * A subtree must include all of its descendants.
 * Here's an example:
 *     10
 *     / \
 *    5  15
 *   / \   \
 *  1   8   7
 * The Largest BST Subtree in this case is the highlighted one.
 * The return value is the subtree's size, which is 3.
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
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


 struct Res {
    int cnt; // tree size
    bool isBst;
    int minVal;
    int maxVal;
 };

class Solution {
    // global maximum
    int largest;
    Res helper(TreeNode *root) {
        Res res;
        res.minVal = res.maxVal = root->val;
        res.cnt = 1;
        res.isBst = true;

        if (root->left) {
            auto leftRes = helper(root->left);
            if (leftRes.isBst && root->val > leftRes.maxVal) {
                res.minVal = leftRes.minVal;
                res.cnt += leftRes.cnt;
            } else {
                res.isBst = false;
            }
        }

        // whether left tree is a BST or not, we need to check the right subtree to obtain
        // global maximum BST size
        if (root->right) {
            auto rightRes = helper(root->right);
            if (res.isBst && rightRes.isBst && root->val < rightRes.minVal) {
                res.maxVal = rightRes.maxVal;
                res.cnt += rightRes.cnt;
            } else {
                res.isBst = false;
                return res;
            }
        }
        this->largest = max(this->largest, res.cnt);
        return res;
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        this->largest = 1;
        helper(root);
        return this->largest;
    }
};

int main() {
    return 0;
}
