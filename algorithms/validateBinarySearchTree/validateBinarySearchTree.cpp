/**
 *
 * Sean
 * 2016-03-03
 *
 * https://leetcode.com/problems/validate-binary-search-tree/
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 */
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// check whether the in-order traversion is sorted.
class Solution {
    private:
        vector<int> results;
        void dfs(TreeNode *root) {
            if (!root) return;
            dfs(root->left);
            results.push_back(root->val);
            dfs(root->right);
        }
public:
    bool isValidBST(TreeNode* root) {
        results.clear();
        dfs(root);
        /**
        if (results.size() <= 1)
            return true;
        int cur = results[0];
        for (int i=1; i<results.size(); ++i) {
            if (cur>=results[i])
                return false;
            cur = results[i];
        }
        return true;
        */
        // use the more succinct is_sorted
        return is_sorted(results.begin(), results.end(),
                [](const int &l, const int &r){
                    return l <= r;
                });
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(1);
    root->left = left;

    Solution s;
    cout << s.isValidBST(root) << endl;
}
