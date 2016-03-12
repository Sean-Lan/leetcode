/**
 *
 * Sean
 * 2016-03-12
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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

/**
 *
 * Divide and conquer.
 * The root is the first element of preorder, find that value in inorder and separate inorder into
 * two parts. The first part is the left sub-tree, and the second is the right sub-tree.
 *
 */

class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty()) return nullptr;
            return buildTree(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
        }
    private:
        TreeNode *buildTree(int preBeg, int preEnd, int inBeg, int inEnd,
                vector<int> &preorder, vector<int> &inorder) {
            if (preBeg > preEnd) return nullptr;
            if (preBeg == preEnd) return new TreeNode(preorder[preBeg]);
            int rootValue = preorder[preBeg];
            TreeNode *root = new TreeNode(rootValue);
            int i = inBeg;
            while (i<=inEnd && inorder[i]!=rootValue) ++i;
            root->left = buildTree(preBeg+1, preBeg+i-inBeg, inBeg, i-1, preorder, inorder);
            root->right = buildTree(preBeg+i-inBeg+1, preEnd, i+1, inEnd, preorder, inorder);
            return root;
        }
};

int main() {
    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    Solution solution;
    solution.buildTree(preorder, inorder);
}
