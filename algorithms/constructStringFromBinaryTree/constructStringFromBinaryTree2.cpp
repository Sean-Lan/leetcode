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
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// iterative solution with a stack
// the first time a node is pop from the stack, append `(node.val` to `path`
// the second time a node is pop from the stack, append `)` to `path`
// note: need to push the right child node to the stack first since we want to visit the left child tree first
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string path = to_string(t->val);
        if (!t->left && t->right) path += "()";

        stack<pair<TreeNode *, bool>> aStack;
        if (t->right) aStack.push({t->right, true});
        if (t->left) aStack.push({t->left, true});

        while (!aStack.empty()) {
            TreeNode *p = aStack.top().first;
            bool isFirst = aStack.top().second;
            aStack.pop();
            if (isFirst) {
                path += "(";
                path += to_string(p->val);
                aStack.push({p, false});
                if (!p->left && p->right)
                    path += "()";
                if (p->right) aStack.push({p->right, true});
                if (p->left) aStack.push({p->left, true});
            } else {
                path += ")";
            }
        }

        return path;
    }
};

int main() {
    return 0;
}
