/**
 *
 * Sean
 * 2016-07-04
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
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

// DFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int total = 0;
        if (root)
            dfs(root, 0, total);
        return total;
    }
private:
    void dfs(TreeNode *root, int sum, int& total) {
        sum *= 10;
        sum += root->val;
        if (!root->left && !root->right) {
            total += sum;
            return;
        }
        if (root->left)
            dfs(root->left, sum, total);
        if (root->right)
            dfs(root->right, sum, total);
    }
};

int main() {}
