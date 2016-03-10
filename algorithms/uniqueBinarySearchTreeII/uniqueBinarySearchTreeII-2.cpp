/**
 *
 * Sean
 * 2016-03-10
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
        vector<TreeNode *> generateTrees(int n) {
            if (n<1) return {};
            vector<vector<Trees>> dp(n+1, vector<Trees>(n+1));
            for (int i=1; i<=n; ++i)
                dp[i][i] = { new TreeNode(i) };

            Trees empty = {nullptr};
            for (int j=1; j<n; ++j)
                for (int i=1; i+j<=n; ++i) {
                    auto &trees = dp[i][i+j];
                    for (int root=i; root<=i+j; ++root) {
                        auto leftTrees = (root-1<i)?empty:dp[i][root-1];
                        auto rightTrees = (root+1>i+j)?empty:dp[root+1][i+j];
                        for (auto &leftTree : leftTrees) {
                            for (auto &rightTree: rightTrees) {
                                TreeNode *rootNode = new TreeNode(root);
                                rootNode->left = leftTree;
                                rootNode->right = rightTree;
                                trees.push_back(rootNode);
                            }
                        }
                    }
                }
            return dp[1][n];
        }
};

int main() {
    Solution s;
    s.generateTrees(1);
    return 0;
}
