/**
 *
 * Sean
 * 2017-10-12
 *
 * https://leetcode.com/problems/binary-tree-paths/
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *       1
 *     /   \
 *     2     3
 *      \
 *        5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
 *
 */
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// backtracking
class Solution {
    string buildPath(vector<int> &path) {
        int n = path.size();
        string s = to_string(path[0]);
        for (int i=1; i<n; ++i) {
            s += "->";
            s += to_string(path[i]);
        }
        return s;
    }
    void solve(TreeNode *root, vector<int> &path, vector<string> &paths) {
        if (!root) return;
        path.push_back(root->val);
        if (root->left) {
            solve(root->left, path, paths);
        }
        if (root->right) {
            solve(root->right, path, paths);
        }
        if (!root->left && !root->right) {
            paths.push_back(buildPath(path));
        }
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> paths;
        solve(root, path, paths);
        return paths;
    }
};

int main() {
    return 0;
}
