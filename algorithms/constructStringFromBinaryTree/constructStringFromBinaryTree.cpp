/**
 *
 * Sean
 * 2017-08-01
 *
 * https://leetcode.com/problems/construct-string-from-binary-tree/description/
 *
 * You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
 *
 * The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
 *
 * Example 1:
 * Input: Binary tree: [1,2,3,4]
 *        1
 *      /   \
 *     2     3
 *    /
 *   4
 *
 * Output: "1(2(4))(3)"
 *
 * Explanation: Originallay it needs to be "1(2(4)())(3()())",
 * but you need to omit all the unnecessary empty parenthesis pairs.
 * And it will be "1(2(4))(3)".
 * Example 2:
 * Input: Binary tree: [1,2,3,null,4]
 *        1
 *      /   \
 *     2     3
 *      \
 *       4
 *
 * Output: "1(2()(4))(3)"
 *
 * Explanation: Almost the same as the first example,
 * except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
 *
 */
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n)
// recursive solution
class Solution {
    void buildString(TreeNode *t, string &path) {
        path.push_back('(');
        path += to_string(t->val);
        if (!t->left && t->right)
            path += "()";

        if (t->left) buildString(t->left, path);
        if (t->right) buildString(t->right, path);
        path.push_back(')');
    }
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string path = to_string(t->val);
        if (!t->left && t->right) path += "()";
        if (t->left) buildString(t->left, path);
        if (t->right) buildString(t->right, path);
        return path;
    }
};

int main() {
    return 0;
}
