/**
 *
 * Sean
 * 2016-06-25
 *
 * https://leetcode.com/problems/path-sum-ii/
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
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

// DFS
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        vector<vector<int>> results;
        vector<int> result;
        helper(root, 0, sum, result, results);
        return results;
    }

    void helper(TreeNode *root, int cumSum, const int &sum, vector<int> &result, vector<vector<int>> &results) {
        result.push_back(root->val);
        cumSum += root->val;
        if (!root->left && !root->right && cumSum==sum)
            results.push_back(result);

        if (root->left)
            helper(root->left, cumSum, sum, result, results);
        if (root->right)
            helper(root->right, cumSum, sum, result, results);
        result.pop_back();
    }
};

int main() {}
