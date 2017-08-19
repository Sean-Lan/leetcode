/**
 *
 * Sean
 * 2017-08-19
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
 *
 * Example 1:
 * Input:
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 *
 * Target = 9
 *
 * Output: True
 * Example 2:
 * Input:
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 *
 * Target = 28
 *
 * Output: False
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n) time and space complexity
// in-order tranverse the BST to get a sorted array, then do the check in O(n)
class Solution {
    void inTrans(TreeNode *root, vector<int> &sorted) {
        if (!root) return;
        inTrans(root->left, sorted);
        sorted.push_back(root->val);
        inTrans(root->right, sorted);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> sorted;
        inTrans(root, sorted);
        int n = sorted.size();
        if (n < 2) return false;

        int s = 0, e = n - 1;
        int sum;
        while (s < e) {
            sum = sorted[s] + sorted[e];
            if (sum == k) return true;
            else if (sum < k) ++s;
            else --e;
        }

        return false;
    }
};

int main() {
    return 0;
}
