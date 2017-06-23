/**
 *
 * Sean
 * 2017-06-24
 *
 * https://leetcode.com/problems/binary-tree-vertical-order-traversal/#/solutions
 *
 * Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 *
 * If two nodes are in the same row and column, the order should be from left to right.
 *
 * Examples:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *    3
 *   /\
 *  /  \
 *  9  20
 *     /\
 *    /  \
 *   15   7
 * return its vertical order traversal as:
 * [
 *   [9],
 *   [3,15],
 *   [20],
 *   [7]
 * ]
 * Given binary tree [3,9,8,4,0,1,7],
 *      3
 *     /\
 *    /  \
 *    9   8
 *   /\  /\
 *  /  \/  \
 *  4  01   7
 * return its vertical order traversal as:
 * [
 *   [4],
 *   [9],
 *   [3,0,1],
 *   [8],
 *   [7]
 * ]
 * Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
 *      3
 *     /\
 *    /  \
 *    9   8
 *   /\  /\
 *  /  \/  \
 *  4  01   7
 *     /\
 *    /  \
 *    5   2
 * return its vertical order traversal as:
 * [
 *   [4],
 *   [9,5],
 *   [3,0,1],
 *   [8,2],
 *   [7]
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

// O(n)
// level order traverse the tree to maintain top-to-down order in a column
// use a number as column index
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        int leftMost = 0, rightMost = 0;
        vector<pair<int, int>> seq;

        queue<pair<int, TreeNode *>> aQueue;
        aQueue.push({0, root});

        int col;
        TreeNode *p;
        while (!aQueue.empty()) {
            auto aPair = aQueue.front();
            col = aPair.first;
            p = aPair.second;
            aQueue.pop();
            seq.push_back({col, p->val});
            if (p->left) {
                leftMost = min(leftMost, col-1);
                aQueue.push({col-1, p->left});
            }
            if (p->right) {
                rightMost = max(rightMost, col+1);
                aQueue.push({col+1, p->right});
            }
        }

        vector<vector<int>> res(-leftMost + rightMost + 1);
        for (auto &aPair : seq) {
            res[aPair.first-leftMost].push_back(aPair.second);
        }

        return res;
    }
};

int main() {
    return 0;
}
