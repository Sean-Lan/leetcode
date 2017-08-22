/**
 *
 * Sean
 * 2017-08-22
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
 *
 * The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
 *
 * Example 1:
 * Input:
 *
 *            1
 *          /   \
 *         3     2
 *        / \     \
 *       5   3     9
 *
 * Output: 4
 * Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
 * Example 2:
 * Input:
 *
 *           1
 *          /
 *         3
 *        / \
 *       5   3
 *
 * Output: 2
 * Explanation: The maximum width existing in the third level with the length 2 (5,3).
 * Example 3:
 * Input:
 *
 *           1
 *          / \
 *         3   2
 *        /
 *       5
 *
 * Output: 2
 * Explanation: The maximum width existing in the second level with the length 2 (3,2).
 * Example 4:
 * Input:
 *
 *           1
 *          / \
 *         3   2
 *        /     \
 *       5       9
 *      /         \
 *     6           7
 * Output: 8
 * Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
 *
 *
 * Note: Answer will in the range of 32-bit signed integer.
 *
 */

#include <iostream>
#include <deque>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS
// similar to array-based heap, pass down a seq along with the TreeNode
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        deque<pair<TreeNode *, int>> Q;
        Q.push_back({root, 1});

        int maxWidth = 1;
        int sz;
        while (!Q.empty()) {
            sz = Q.size();
            maxWidth = max(maxWidth, Q.back().second-Q.front().second+1);
            for (int i=0; i<sz; ++i) {
                auto p = Q.front().first;
                auto seq = Q.front().second;
                Q.pop_front();
                if (p->left) { Q.push_back({p->left, seq*2}); }
                if (p->right) { Q.push_back({p->right, seq*2+1}); }
            }
        }
        return maxWidth;
    }
};

int main() {
    return 0;
}
