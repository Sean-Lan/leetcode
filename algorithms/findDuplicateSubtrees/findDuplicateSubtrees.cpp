/**
 *
 * Sean
 * 2017-08-01
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
 *
 * Two trees are duplicate if they have the same structure with same node values.
 *
 * Example 1:
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   2   4
 *        /
 *       4
 *
 * The following are two duplicate subtrees:
 *       2
 *      /
 *     4
 *
 * and
 *     4
 *
 * Therefore, you need to return above trees' root in the form of a list.
 *
 */
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n^2)
// serialize the tree
class Solution {
    unordered_map<string, vector<TreeNode *>> table;
    string serialize(TreeNode *root) {
        if (!root) return "";
        string s = '(' + serialize(root->left) + to_string(root->val) + serialize(root->right) + ')';
        table[s].push_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        this->table.clear();
        serialize(root);

        vector<TreeNode *> res;
        for (auto &p : table) {
            if (p.second.size() > 1) {
                res.push_back(p.second.front());
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
