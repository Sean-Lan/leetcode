/**
 *
 * Sean
 * 2016-06-08
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// First level order tranverse the tree, then reverse the vector.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode *, int>> aQueue;
        vector<vector<int>> results;
        aQueue.push({root, 0});
        while (!aQueue.empty()) {
            auto aPair = aQueue.front();
            aQueue.pop();
            if (results.size()<= aPair.second) {
                results.push_back({aPair.first->val});
            } else {
                results[aPair.second].push_back(aPair.first->val);
            }
            if (aPair.first->left) aQueue.push({aPair.first->left, aPair.second+1});
            if (aPair.first->right) aQueue.push({aPair.first->right, aPair.second+1});
        }
        reverse(results.begin(), results.end());
        return results;
    }
};

int main() {}
