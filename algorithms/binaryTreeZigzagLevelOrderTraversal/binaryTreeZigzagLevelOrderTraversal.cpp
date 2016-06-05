/**
 *
 * Sean
 * 2016-06-05
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// first level order tranversal, then reverse the odd indexed level.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> results;
        queue<pair<TreeNode *, int>> aQueue;
        aQueue.push({root, 0});

        while (!aQueue.empty()) {
            auto aPair = aQueue.front();
            aQueue.pop();
            if (results.size() <= aPair.second) {
                results.push_back({aPair.first->val});
            } else {
                results[aPair.second].push_back(aPair.first->val);
            }
            if (aPair.first->left)
                aQueue.push({aPair.first->left, aPair.second+1});
            if (aPair.first->right)
                aQueue.push({aPair.first->right, aPair.second+1});
        }

        // zig-zag
        for (int i=0; i<results.size(); ++i) {
            if (i&1)
                reverse(results[i].begin(), results[i].end());
        }
        return results;
    }
};

int main() {}
