/**
 *
 * Sean
 * 2017-03-06
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/?tab=Description
 *
 * Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
 *
 * Examples 1
 * Input:
 *
 *   5
 *  /  \
 * 2   -3
 * return [2, -3, 4], since all the values happen only once, return all of them in any order.
 *
 * Examples 2
 * Input:
 *
 *   5
 *  /  \
 * 2   -5
 * return [2], since 2 happens twice, however -5 only occur once.
 *
 */
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

// DFS O(n)
class Solution {

    int getSum(TreeNode *root, unordered_map<int, int> &counts) {
        if (!root) return 0;
        int sum = root->val;
        if (root->left) sum += getSum(root->left, counts);
        if (root->right) sum += getSum(root->right, counts);
        ++ counts[sum];
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> counts;
        getSum(root, counts);

        int maxCnt = 0;
        for (auto aPair : counts) {
            maxCnt = max(maxCnt, aPair.second);
        }

        vector<int> res;
        for (auto aPair : counts) {
            if (aPair.second == maxCnt) {
                res.push_back(aPair.first);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
