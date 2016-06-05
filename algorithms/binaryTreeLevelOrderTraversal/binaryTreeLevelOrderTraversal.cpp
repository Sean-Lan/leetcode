/**
 *
 * Sean
 * 2016-06-05
 *
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS using a Queue.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return results;
    }
};

int main() {}
