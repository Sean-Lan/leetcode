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
#include <string>
using namespace std;

// let m be the number of non-empty nodes of a binary tree and n be the number of empty nodes
// m + 1 = n
//
// short proof:
// 1) empty tree holds true
// 2) every time we insert a node into a tree, both of the number of non-empty nodes and empty nodes get increased by 1
//
// `r` is number of non-empty nodes
// every time we meet a empty node, i.e., #, --r
// every time we meet a non-empty node, ++r
// if r < 0, we break the loop and check whether we have visited the whole tree
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false;
        preorder += ',';
        int n = preorder.size();
        int r = 0;
        int i;
        for (i=0; i<n; ++i) {
            if (preorder[i] != ',') continue;
            if (preorder[i-1] == '#') {
                -- r;
                if (r < 0) break;
            } else {
                ++ r;
            }
        }

        return i == n-1;
    }
};

int main() {
    return 0;
}
