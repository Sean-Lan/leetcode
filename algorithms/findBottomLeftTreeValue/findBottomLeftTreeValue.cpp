/**
 *
 * Sean
 * 2017-02-16
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/
 *
 * Given a binary tree, find the leftmost value in the last row of the tree.
 *
 * Example 1:
 * Input:
 * 
 *     2
 *    / \
 *   1   3
 * 
 * Output:
 * 1
 *
 * Example 2: 
 * Input:
 * 
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   5   6
 *        /
 *       7
 * 
 * Output:
 * 7
 *
 * Note: You may assume the tree (i.e., the given root node) is not NULL.
 *
 */

#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode *, int>> aQueue;
        aQueue.push({root, 0});
        int curVal = root->val;
        int curLevel = 0;
        
        while (!aQueue.empty()) {
            auto cur = aQueue.front();
            aQueue.pop();
            auto curNode = cur.first;
            auto nextLevel = cur.second + 1;
            if (curNode -> left) {
                if (nextLevel > curLevel) {
                    curVal = curNode->left->val;
                    curLevel = nextLevel;
                }
                aQueue.push({curNode->left, nextLevel});
            } 
            if (curNode -> right) {
                if (nextLevel > curLevel) {
                    curVal = curNode->right->val;
                    curLevel = nextLevel;
                }
                aQueue.push({curNode->right, nextLevel});
            }
        }
        return curVal;
    }
};
