/**
 *
 * Sean
 * 2016-03-15
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w
 * as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *        _______3______
 *       /              \
 *    ___5__          ___1__
 *   /      \        /      \
 *   6      _2       0       8
 *         /  \
 *         7   4
 *
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5,
 * since a node can be a descendant of itself according to the LCA definition.
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

// use DFS to find the path from root to p and q, then find the lowest.
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            vector<TreeNode *> pPath = {root};
            vector<TreeNode *> qPath = {root};
            dfs(root, pPath, p);
            dfs(root, qPath, q);
            int i=0;
            // be careful! i should not cross the vector bound.
            while (i<pPath.size() && i<qPath.size() && pPath[i]==qPath[i]) ++i;
            return pPath[i-1];
        }

        bool dfs(TreeNode *current, vector<TreeNode *> &path, TreeNode *target) {
            if (current == target) {
                return true;
            }
            if (current->left) {
                path.push_back(current->left);
                if (dfs(current->left, path, target))
                    return true;
                path.pop_back();
            }
            if (current->right) {
                path.push_back(current->right);
                if (dfs(current->right, path, target))
                    return true;
                path.pop_back();
            }
            return false;
        }

        void printPath(vector<TreeNode *> &path) {
            for (auto &p : path)
                cout << p->val <<  ' ';
            cout << endl;
        }
};

int main() {
    TreeNode *three = new TreeNode(3);
    TreeNode *five = new TreeNode(5);
    TreeNode *one = new TreeNode(1);
    TreeNode *six = new TreeNode(6);
    TreeNode *two = new TreeNode(2);
    TreeNode *zero = new TreeNode(0);
    TreeNode *eight = new TreeNode(8);
    TreeNode *seven = new TreeNode(7);
    TreeNode *four = new TreeNode (4);

    three->left = five;
    three->right = one;
    five->left = six;
    five->right = two;
    one->left = zero;
    one->right = eight;

    two->left = seven;
    two->right = four;

    TreeNode *n37 = new TreeNode(37);
    TreeNode *n_34 = new TreeNode(-34);
    TreeNode *n_48 = new TreeNode(-48);
    TreeNode *n_100 = new TreeNode(-100);
    TreeNode *n_101 = new TreeNode(-101);
    TreeNode *n48 = new TreeNode(48);
    TreeNode *n_54 = new TreeNode(-54);
    TreeNode *n_71 = new TreeNode(-71);
    TreeNode *n_22 = new TreeNode(-22);
    TreeNode *n8 = new TreeNode(8);

    n37->left = n_34;
    n37->right = n_48;
    n_34->right = n_100;
    n_48->left = n_101;
    n_48->right = n48;
    n_101->left = n_54;
    n48->left = n_71;
    n48->right = n_22;
    n_71->right = n8;

    Solution solution;
    TreeNode *common = solution.lowestCommonAncestor(n37, n_71, n48);
    cout << common->val << endl;


}
