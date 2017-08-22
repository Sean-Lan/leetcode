/**
 *
 * Sean
 * 2017-08-22
 *
 * https://leetcode.com/problems/equal-tree-partition/description/
 *
 * Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.
 *
 * Example 1:
 * Input:
 *     5
 *    / \
 *   10 10
 *     /  \
 *    2   3
 *
 * Output: True
 * Explanation:
 *     5
 *    /
 *   10
 *
 * Sum: 15
 *
 *    10
 *   /  \
 *  2    3
 *
 * Sum: 15
 * Example 2:
 * Input:
 *     1
 *    / \
 *   2  10
 *     /  \
 *    2   20
 *
 * Output: False
 * Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
 * Note:
 * The range of tree node value is in the range of [-100000, 100000].
 * 1 <= n <= 10000
 *
 */

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n)
// first pass to calculate the sum of the subtree, then check whether the sum/2 shows.
class Solution {
    unordered_set<int> count;
    int getSum(TreeNode *root, bool isRoot) {
        if (!root) return 0;
        int sum = root->val +
            getSum(root->left, false) + getSum(root->right, false);
        if (!isRoot) count.insert(sum);
        return sum;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int total = getSum(root, true);
        if (total & 1) return false;
        int target = total/2;
        return count.count(target);
    }
};

int main() {
    return 0;
}
