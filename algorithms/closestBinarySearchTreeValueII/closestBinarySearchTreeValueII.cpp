/**
 *
 * Sean
 * 2017-06-12
 *
 * https://leetcode.com/problems/closest-binary-search-tree-value-ii/#/description
 *
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 *
 * Note:
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 *
 * Follow up:
 * Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
 *
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n)
// 1. tranverse the BST to get the sorted array
// 2. find the nearest one number
// 3. find the nearest k numbers starting from the two directions at the nearest one
class Solution {
    void inTrans(TreeNode *root, vector<int> &sorted) {
        if (root->left) inTrans(root->left, sorted);
        sorted.push_back(root->val);
        if (root->right) inTrans(root->right, sorted);
    }

public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if (k <= 0) return {};
        vector<int> sorted;
        inTrans(root, sorted);
        int n = sorted.size();
        double minDelta = abs(sorted[0] - target);
        int best = 0;

        double delta;
        for (int i=1; i<n; ++i) {
            delta = abs(sorted[i] - target);
            if (delta < minDelta) {
                minDelta = delta;
                best = i;
            }
        }

        vector<int> res = {sorted[best]};
        --k;
        int i=best-1, j=best+1;

        double delta1, delta2;
        if (i>=0) delta1 = abs(target - sorted[i]);
        if (j<n) delta2 = abs(target - sorted[j]);
        while (i>=0 && j<n && k) {
            if (delta1 > delta2) {
                res.push_back(sorted[j++]);
                if (j<n) delta2 = abs(target - sorted[j]);
            } else {
                res.push_back(sorted[i--]);
                if (i>=0) delta1 = abs(target - sorted[i]);
            }
            --k;
        }

        while (i>=0 && k) {
            res.push_back(sorted[i--]);
            --k;
        }

        while (j<n && k) {
            res.push_back(sorted[j++]);
            --k;
        }

        return res;
    }
};

int main() {
    return 0;
}
