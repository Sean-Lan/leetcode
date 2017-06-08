/**
 *
 * Sean
 * 2017-06-08
 *
 * https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/#/description
 *
 * Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
 *
 * You may assume each number in the sequence is unique.
 *
 * Follow up:
 * Could you do it using only constant space complexity?
 *
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// use the original array as stack, O(1) space complexity and O(n) time complexity
// reference to https://discuss.leetcode.com/topic/21466/72ms-c-solution-using-one-stack-o-n-time-and-space/2
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n <= 2) return true;
        // use the preorder array as a stack;
        int sp = 1;
        int root = INT_MIN; // the root of prev subtree
        int cur;
        for (int i=1; i<n; ++i) {
            cur = preorder[i];
            if (sp > 0 && cur < preorder[sp-1]) { // cur must be in the right subtree of root
                if (cur < root) return false;
                preorder[sp++] = cur;
            } else {
                while (sp > 0 && preorder[sp-1] < cur) {
                    root = preorder[sp-1];
                    --sp;
                }
                preorder[sp++] = cur;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
