/**
 *
 * Sean
 * 2017-08-01
 *
 * Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.
 *
 * The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.
 *
 * Example 1:
 * Input:
 * A binary tree as following:
 *        4
 *      /   \
 *     2     6
 *    / \   /
 *   3   1 5
 *
 * v = 1
 *
 * d = 2
 *
 * Output:
 *        4
 *       / \
 *      1   1
 *     /     \
 *    2       6
 *   / \     /
 *  3   1   5
 *
 * Example 2:
 * Input:
 * A binary tree as following:
 *       4
 *      /
 *     2
 *    / \
 *   3   1
 *
 * v = 1
 *
 * d = 3
 *
 * Output:
 *       4
 *      /
 *     2
 *    / \
 *   1   1
 *  /     \
 * 3       1
 * Note:
 * The given d is in range [1, maximum depth of the given tree + 1].
 * The given binary tree has at least one tree node.
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

// level order tranversal
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *p = new TreeNode(v);
            p->left = root;
            return p;
        }

        int cnt = 1;
        queue<TreeNode *> Q;
        Q.push(root);

        int sz;
        bool arrived = false;
        while (!Q.empty()) {
            if (++cnt == d) arrived = true;
            sz = Q.size();
            for (int i=0; i<sz; ++i) {
                TreeNode *cur = Q.front();
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
                Q.pop();
                if (arrived) {
                    TreeNode *p = new TreeNode(v);
                    p->left = cur->left;
                    cur->left = p;
                    p = new TreeNode(v);
                    p->right = cur->right;
                    cur->right = p;
                }
            }
            if (arrived) break;
        }
        return root;
    }
};

int main() {
    return 0;
}
