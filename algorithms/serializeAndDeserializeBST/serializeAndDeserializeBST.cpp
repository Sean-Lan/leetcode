/**
 *
 * Sean
 * 2017-01-10
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/
 *
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
 *
 * The encoded string should be as compact as possible.
 *
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 *
 * Show Company Tags
 * Show Tags
 * Show Similar Problems
 *
 */
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Just pre-order visit the tree, and then construct the tree from pre-order visiting string.
class Codec {
    void preOrder(TreeNode *root, vector<int> &iVec) {
        iVec.push_back(root->val);
        if (root->left) preOrder(root->left, iVec);
        if (root->right) preOrder(root->right, iVec);
    }
    
    string iVecToString(const vector<int> &iVec, char sep) {
        if (iVec.empty()) return "";
        int n = iVec.size();
        string res = to_string(iVec[0]);
        for (int i=1; i<n; ++i) {
            res += sep;
            res += to_string(iVec[i]);
        }
        return res;
    }

    vector<int> stringToIVec(const string &s, char sep) {
        if (s.empty()) return {};
        vector<int> iVec;
        int n = s.size();
        int start = 0;
        int i;
        for (i=0; i<n; ++i) {
            if (s[i] == sep) {
                string tmp = s.substr(start, i-start);
                iVec.push_back(atoi(tmp.c_str()));
                start = i+1;
            }
        }
        string tmp = s.substr(start, i-start);
        iVec.push_back(atoi(tmp.c_str()));
        return iVec;
    }
    
    TreeNode *buildTree(const vector<int> &nodes, int start, int end) {
        int rootValue = nodes[start];
        TreeNode *root = new TreeNode(rootValue);
        int leftStart = start+1;
        int leftEnd;
        for (leftEnd=leftStart; leftEnd<=end; ++leftEnd) {
            if (nodes[leftEnd] > rootValue) {
                break;
            }
        }
        --leftEnd;
        int rightStart = leftEnd+1;
        if (leftStart <= leftEnd) {
            root->left = buildTree(nodes, leftStart, leftEnd);
        }
        if (rightStart <= end) {
            root->right = buildTree(nodes, rightStart, end);
        }
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> nodes;
        if (root) preOrder(root, nodes);
        return iVecToString(nodes, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nodes = stringToIVec(data, ',');
        if (nodes.empty()) return nullptr;
        return buildTree(nodes, 0, nodes.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
