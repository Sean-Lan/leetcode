/**
 *
 * Sean
 * 2017-08-01
 *
 * https://leetcode.com/problems/construct-binary-tree-from-string/description/
 *
 * You need to construct a binary tree from a string consisting of parenthesis and integers.
 *
 * The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
 *
 * You always start to construct the left child node of the parent first if it exists.
 *
 * Example:
 * Input: "4(2(3)(1))(6(5))"
 * Output: return the tree root node representing the following tree:
 *
 *        4
 *      /   \
 *     2     6
 *    / \   /
 *   3   1 5
 * Note:
 * There will only be '(', ')', '-' and '0' ~ '9' in the input string.
 * An empty tree is represented by "" instead of "()".
 *
 */
#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n)
// everytime meets a `(`, create a new TreeNode, and set it as a child of the TreeNode on the top of the stack, and push it into the stack
// everytime meets a `)`, pop a TreeNode from the stack.
// One thing to note is that the number may contain a `-`
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        int n = s.size();
        int i = 0;
        int num = 0;
        stack<TreeNode *> aStack;
        bool positive = true;
        if (s[i] == '-') {
            positive = false;
            ++i;
        }

        while (isdigit(s[i])) {
            num = num*10 + s[i]-'0';
            ++i;
        }

        TreeNode *root = new TreeNode(positive ? num : -num);
        aStack.push(root);

        while (i<n) {
            if (s[i] == '(') {
                ++i;
                num = 0;
                if (s[i] == '-') {
                    positive = false;
                    ++i;
                } else {
                    positive = true;
                }
                while (isdigit(s[i])) {
                    num = num*10 + s[i]-'0';
                    ++i;
                }
                TreeNode *p = new TreeNode(positive ? num : -num);
                if (aStack.top()->left) {
                    aStack.top()->right = p;
                } else {
                    aStack.top()->left = p;
                }
                aStack.push(p);
            } else if (s[i] == ')') {
                ++i;
                aStack.pop();
            }
        }

        return aStack.top();
    }
};

int main() {
    return 0;
}
