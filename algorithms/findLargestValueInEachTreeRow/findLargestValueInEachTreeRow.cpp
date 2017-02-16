/**
 *
 * Sean
 * 2017-02-16
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 *
 * You need to find the largest value in each row of a binary tree.
 *
 * Example:
 * Input:
 *
 *           1
 *          / \
 *         3   2
 *        / \   \
 *       5   3   9
 *
 * Output: [1, 3, 9]
 *
 */

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

// level order tranverse
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> maxVals = {root->val};
        queue<pair<TreeNode *, int>> aQueue;
        aQueue.push({root, 0});

        while (!aQueue.empty()) {
            auto cur = aQueue.front();
            aQueue.pop();
            auto curNode = cur.first;
            auto nextLevel = cur.second + 1;
            vector<TreeNode *> nextNodes = {curNode->left, curNode->right};
            for (auto nextNode : nextNodes) {
                if (nextNode) {
                    if (maxVals.size() <= nextLevel) {
                        maxVals.push_back(nextNode->val);
                    } else {
                        maxVals[nextLevel] = max(maxVals[nextLevel], nextNode->val);
                    }
                    aQueue.push({nextNode, nextLevel});
                }
                nextNode = curNode->right;
            }
        }
        return maxVals;
    }
};
