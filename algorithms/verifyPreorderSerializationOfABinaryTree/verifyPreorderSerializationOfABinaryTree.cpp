/**
 *
 * Sean
 * 2017-06-29
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/#/description
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 *
 *      _9_
 *     /   \
 *    3     2
 *   / \   / \
 *  4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 *
 * Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 *
 * Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 *
 * You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
 *
 * Example 1:
 * "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Return true
 *
 * Example 2:
 * "1,#"
 * Return false
 *
 * Example 3:
 * "9,#,#,1"
 * Return false
 *
 */
#include <stack>
#include <string>
using namespace std;

// every time we meet a #, check whether the top of the stack is a #, if it does,
// we could pop the # and the number in it because it means a end of a child tree.
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if (n == 0) return false;
        if (n == 1) return preorder == "#";
        preorder.push_back(',');
        ++n;
        stack<string> aStack;

        int last = 0;
        string token;
        for (int i=0; i<n; ++i) {
            if (preorder[i] == ',') {
                token = preorder.substr(last, i-last);
                last = i+1;
                if (token == "#") {
                    if (aStack.empty()) return false;
                    while (aStack.top() == "#") {
                        aStack.pop();
                        if (aStack.empty()) return false;
                        aStack.pop(); // number node
                        if (aStack.empty()) break;
                    }
                    aStack.push(token);
                } else {
                    aStack.push(token);
                }
            }
        }
        return aStack.size() == 1 && aStack.top() == "#";
    }
};

int main() {
    return 0;
}
