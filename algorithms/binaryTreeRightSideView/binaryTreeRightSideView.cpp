/**
 *
 * Sean
 * 2016-03-31
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/
 *
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 * You should return [1, 3, 4].
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode *, int>> aQueue;
        aQueue.push({root, 0});
        pair<TreeNode *, int> current;
        vector<int> result;
        while (!aQueue.empty()) {
            current = aQueue.front();
            aQueue.pop();
            if (result.size()<current.second+1)
                result.push_back(current.first->val);
            else
                result[current.second] = current.first->val;
            if (current.first->left)
                aQueue.push({current.first->left, current.second+1});
            if (current.first->right)
                aQueue.push({current.first->right, current.second+1});
        }
        return result;
    }
};

int main() {}
