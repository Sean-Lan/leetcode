/**
 *
 * Sean
 * 2016-07-20
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 *
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 *
 * For example, you may serialize the following tree
 *
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Use level-visit the tree and serialize it into 1,2,3,#,#,4,5,#,#,#,#
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        queue<TreeNode *> aQueue;
        if (!root)
            os << "#";
        else {
            os << root->val;
            aQueue.push(root->left);
            aQueue.push(root->right);
        }
        while (!aQueue.empty()) {
            TreeNode *cur = aQueue.front();
            aQueue.pop();
            os << ",";
            if (!cur)
                os << "#";
            else {
                os << cur->val;
                aQueue.push(cur->left);
                aQueue.push(cur->right);
            }
        }
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode *> nodes;
        int last=0, cur=0;
        int len = data.size();
        string value;
        int intValue;
        for (; cur < len; ++cur) {
            if (data[cur] == ',') {
                value = data.substr(last, cur-last);
                last = cur+1;
                if (value == "#") {
                    nodes.push_back(nullptr);
                } else {
                    istringstream is(value);
                    is >> intValue;
                    nodes.push_back(new TreeNode(intValue));
                }
            }
        }
        nodes.push_back(nullptr);

        int p1 = 0, p2 = 1;
        for (; p1<nodes.size(); ++p1) {
            if (nodes[p1]) {
                nodes[p1] -> left = nodes[p2++];
                nodes[p1] -> right = nodes[p2++];
            }
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec codec;
    TreeNode one(1), two(2), three(3);
    one.right = &two;
    two.left = &three;

    codec.deserialize(codec.serialize(&one));

}

