/**
 *
 * Sean
 * 2020-04-19
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

class Solution {
  public:
    int numTrees(int n) {
      if (n <= 1) return 1;
      vector<int> dp(n+1, 0);
      dp[0] = dp[1] = 1;

      for (int i=2; i<=n; ++i) {
        for (int j=1; j<=i; ++j) {
          dp[i] += dp[j-1] * dp[i-j];
        }
      }

      return dp[n];
    }
};

int main() {
  Solution solution;
  cout << solution.numTrees(3) << endl;
}
