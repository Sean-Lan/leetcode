#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// follow the hint, use two stacks to save the path for preds and succs of target
// the top of preds is the largest node <= value, which means the right child of the node must be null or > value
// the top of succs is the mallest node >= value, which means the left child of the node must be null or < value
// to find the next pred, go left first, then find the right-most node
// to find the next succ, go right first, then find the left-most node
class Solution {
    void buildPred(TreeNode *root, double target, stack<TreeNode *> &preds) {
        while (root) {
            if (root->val == target) {
                preds.push(root);
                break;
            } else if (root->val < target) {
                preds.push(root);
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

    void buildSucc(TreeNode *root, double target, stack<TreeNode *> &succs) {
        while (root) {
            if (root->val == target) {
                succs.push(root);
                break;
            } else if (root->val < target) {
                root = root -> right;
            } else {
                succs.push(root);
                root = root->left;
            }
        }
    }

    void movePred(stack<TreeNode *> &preds) {
        TreeNode *root = preds.top();
        preds.pop();
        root = root->left;
        while (root) {
            preds.push(root);
            root = root->right;
        }
    }

    void moveSucc(stack<TreeNode *> &succs) {
        TreeNode *root = succs.top();
        succs.pop();
        root = root->right;
        while (root) {
            succs.push(root);
            root = root->left;
        }
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode *> preds, succs;
        buildPred(root, target, preds);
        buildSucc(root, target, succs);
        if (!preds.empty() && !succs.empty() && preds.top()->val == succs.top()->val) { // target exists in the tree
            movePred(preds);
        }

        vector<int> res;
        int pred, succ;
        while (k--) {
            if (succs.empty()) {
                res.push_back(preds.top()->val);
                movePred(preds);
                continue;
            }
            if (preds.empty()) {
                res.push_back(succs.top()->val);
                moveSucc(succs);
                continue;
            }

            pred = preds.top()->val;
            succ = succs.top()->val;

            if (target-pred > succ-target) {
                res.push_back(succ);
                moveSucc(succs);
            } else {
                res.push_back(pred);
                movePred(preds);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
