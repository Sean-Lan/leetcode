/**
 *
 * Sean
 * 2017-07-30
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 *
 * Example 1:
 * Input:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
 * Note:
 * The range of node's value is in the range of 32-bit signed integer.
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

// BFS
class Solution {
    typedef long long ll;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;

        queue<TreeNode *> aQueue;
        aQueue.push(root);

        ll sum;
        while (!aQueue.empty()) {
            int sz = aQueue.size();
            sum = 0;
            for (int i=0; i<sz; ++i) {
                TreeNode *p = aQueue.front();
                aQueue.pop();

                sum += p->val;
                if (p->left) aQueue.push(p->left);
                if (p->right) aQueue.push(p->right);
            }
            res.push_back((double)sum/sz);
        }

        return res;
    }
};

int main() {
    return 0;
}
