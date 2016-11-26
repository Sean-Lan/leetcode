/**
 *
 * Sean
 * 2016-11-26
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

// Typical DFS
class Solution {
    void dfs(TreeNode *root, vector<int> &curPath, vector<vector<int>> &results) {
        if (!root) return;
        curPath.push_back(root->val);
        bool isLeaf = true;
        if (root->left) {
            isLeaf = false;
            dfs(root->left, curPath, results);
        }
        if (root->right) {
            isLeaf = false;
            dfs(root->right, curPath, results);
        }
        if (isLeaf) {
            results.push_back(curPath);
        }
        curPath.pop_back();
    }
    string buildPath(vector<int> &path) {
        string sPath = to_string(path[0]);
        for (int i=1; i<path.size(); ++i) {
            sPath += "->";
            sPath += to_string(path[i]);
        }
        return sPath;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> results;
        vector<string> paths;
        vector<int> curPath;
        dfs(root, curPath, results);
        for (auto &path : results) {
            paths.push_back(buildPath(path));
        }
        return paths;
    }
};

int main() {
    return 0;
}
