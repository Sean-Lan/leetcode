/**
 *
 * Sean
 * 2016-05-02
 *
 * https://leetcode.com/problems/unique-binary-search-trees/
 *
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp = {1, 1, 2};

// dp
class Solution {
    public:
        int numTrees(int n) {
            int nextVal = 0;
            while (n >= dp.size()) {
                nextVal = 0;
                for (int i=1; i<=dp.size(); ++i) {
                    nextVal += dp[i-1]*dp[dp.size()-i];
                }
                dp.push_back(nextVal);
            }
            return dp[n];
        }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
}
