/**
 *
 * Sean
 * 2017-09-10
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
 *
 * Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
 *
 * If no such second minimum value exists, output -1 instead.
 *
 * Example 1:
 * Input:
 *     2
 *    / \
 *   2   5
 *      / \
 *     5   7
 *
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 * Example 2:
 * Input:
 *     2
 *    / \
 *   2   2
 *
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest value.
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

// first find the smallest value, then use the smallest value to
// find the second smallest value recursively
class Solution {
    int find(TreeNode *root, int smallest) {
        if (!root) return -1;
        if (root->val != smallest) return root->val;
        int left = find(root->left, smallest);
        int right = find(root->right, smallest);
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int smallest = root->val;
        int second = find(root, smallest);

        return second;
    }
};

int main() {
    return 0;
}
