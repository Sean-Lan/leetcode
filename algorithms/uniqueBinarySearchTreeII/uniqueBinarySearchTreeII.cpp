/**
 *
 * Sean
 * 2016-03-10
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/
 *
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 */
#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct PairHash {
    size_t operator()(const pair<int, int> &aPair) const {
        return aPair.first*31 * aPair.second;
    }
};

/**
 *
 * Recursively generate the BTSs, and use a hash table to cache the intermediate results.
 *
 */
unordered_map<pair<int, int>, vector<TreeNode *>, PairHash> cache;

class Solution {
    public:
        vector<TreeNode *> generateTrees(int n) {
            if (n<1) return {};
            auto range = std::make_pair(1,n);
            if (cache.count(range))
                return cache[range];
            generateTrees(1, n);
            return cache[range];
        }

    private:
        void generateTrees(int first, int last) {
            if (first > last)
                return;
            auto range = std::make_pair(first, last);
            if (cache.count(range))
                return;
            if (first == last) {
                cache[range] = {new TreeNode(first)};
                return;
            }
            vector<TreeNode *>trees;
            for (int i=first; i<=last; ++i) {
                generateTrees(first, i-1);
                generateTrees(i+1, last);
                vector<TreeNode *> empty = {nullptr};
                auto leftTrees = (first>i-1)?empty:cache[make_pair(first, i-1)];
                auto rightTrees = (i+1>last)?empty:cache[make_pair(i+1, last)];
                for (auto &leftTree: leftTrees) {
                    for (auto &rightTree: rightTrees) {
                        TreeNode *root = new TreeNode(i);
                        root->left = leftTree;
                        root->right = rightTree;
                        trees.push_back(root);
                    }
                }
            }
            cache[range] = trees;
        }
};

int main() {
    Solution s;
    s.generateTrees(1);
    return 0;
}
