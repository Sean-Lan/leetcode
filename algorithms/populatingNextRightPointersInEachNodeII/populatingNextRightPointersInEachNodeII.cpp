/**
 *
 * Sean
 * 2016-06-26
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 *
 * After calling your function, the tree should look like:
 *
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 *
 */
#include <iostream>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// DFS.
// One thing very *important* is that the recursive order should be right first.
// The invariant is that at from root to the right the next links are established correctly,
// and it requires right first recursion order.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root) {
            root->next = nullptr;
            helper(root);
        }
    }

    void helper(TreeLinkNode *root) {
        if (root) {
            if (root->left) {
                if (root->right) {
                    root->left->next = root->right;
                    root->right->next = getNext(root->next);
                } else
                    root->left->next = getNext(root->next);
            } else {
                if (root->right)
                    root->right->next = getNext(root->next);
            }
            // right first !!! very important!!!
            helper(root->right);
            helper(root->left);
        }
    }

    TreeLinkNode *getNext(TreeLinkNode *root) {
        while (root) {
            if (root->left)
                return root->left;
            if (root->right)
                return root->right;
            root = root->next;
        }
        return nullptr;
    }
};

int main() {}
