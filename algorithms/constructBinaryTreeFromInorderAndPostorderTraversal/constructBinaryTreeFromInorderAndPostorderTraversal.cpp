/**
 *
 * Sean
 * 2016-03-12
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
 * The root value is the last element of the postorder. Find the root value in inorder and separate inorder
 * into two parts. The first part is the left sub-tree and the second part is the right sub-tree.
 *
 */
class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if (inorder.empty()) return nullptr;
            return buildTree(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder);
        }

    private:
        TreeNode *buildTree(int inBeg, int inEnd, int postBeg, int postEnd,
                vector<int> &inorder, vector<int> &postorder) {
            if (inBeg > inEnd)
                return nullptr;
            if (inBeg == inEnd)
                return new TreeNode(inorder[inBeg]);
            int rootValue = postorder[postEnd];
            TreeNode *root = new TreeNode(rootValue);
            int i=0;
            while (rootValue!=inorder[i]) ++i;
            root->left = buildTree(inBeg, i-1, postBeg, postBeg+i-inBeg-1, inorder, postorder);
            root->right = buildTree(i+1, inEnd, postBeg+i-inBeg, postEnd-1, inorder, postorder);
            return root;
        }
};
int main() {
    vector<int> inorder = {1,2,3,4};
    vector<int> postorder = {3,2,4,1};
    Solution solution;
    solution.buildTree(inorder, postorder);
}
