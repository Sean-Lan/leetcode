/**
 *
 * Sean
 * 2016-05-02
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/
 *
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
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
 * Use dp.
 * From the diagonal to the top-right corner.
 * dp[i][i+j] means possible BTSs comprised of i..i+j.
 *
 */

class Solution {
public:
    typedef vector<TreeNode *> Trees;
    vector<TreeNode*> generateTrees(int n) {
        if (n<1) return {};
        vector<vector<Trees>> dp(n+1, vector<Trees>(n+1));
        for (int i=1; i<=n; ++i)
            dp[i][i] = { new TreeNode(i) };
        Trees empty = { nullptr };
        for (int l = 2; l<=n; ++l) {
            for (int i=1; i+l-1<=n; ++i) {
                Trees trees;
                for (int j=i; j<=i+l-1; ++j) {
                    auto &leftTrees = j-1>=i?dp[i][j-1]:empty;
                    auto &rightTrees = j+1<=i+l-1?dp[j+1][i+l-1]:empty;
                    for (auto &leftTree : leftTrees)
                        for (auto &rightTree: rightTrees) {
                            TreeNode *root = new TreeNode(j);
                            root->left = leftTree;
                            root->right = rightTree;
                            trees.push_back(root);
                        }
                }
                dp[i][i+l-1] = trees;
            }
        }
        return dp[1][n];
    }
};

int main() {}
