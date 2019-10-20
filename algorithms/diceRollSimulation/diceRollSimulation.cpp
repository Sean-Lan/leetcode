/**
 *
 * Sean
 * 2019-10-20
 *
 * https://leetcode.com/problems/dice-roll-simulation
 *
 * A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
 *
 * Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.
 *
 * Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.
 *
 * Example 1:
 *
 * Input: n = 2, rollMax = [1,1,2,2,2,3]
 * Output: 34
 * Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
 *
 * Example 2:
 *
 * Input: n = 2, rollMax = [1,1,1,1,1,1]
 * Output: 30
 * Example 3:
 *
 * Input: n = 3, rollMax = [1,1,1,2,2,3]
 * Output: 181
 *
 * Constraints:
 *
 * 1 <= n <= 5000
 * rollMax.length == 6
 * 1 <= rollMax[i] <= 15
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  typedef long long LL;
  LL N = 1000000000 + 7;
  public:
    // O(n * max(rollMax) * 6)
    int dieSimulator(int n, vector<int>& rollMax) {
      // Note: needs to initialize the arrays
      // dp[j][k]: the number of possible sequences with trailing `k` consecutive `j`s.
      LL dp[6][16] = {{0}};

      // sum[j]: the number of possible sequences with trailing `j`.
      LL sum[6] = {0};

      // number of all possible sequences
      LL total = 6;

      for (int i=0; i<6; ++i) {
        dp[i][1] = 1;
        sum[i] = 1;
      }

      for (int i=2; i<=n; ++i) {
        LL currentTotal = 0;
        for (int j=0; j<6; ++j) {
          LL currentSum = 0;
          // length >= 2
          for (int k=min(rollMax[j], i); k>=2; --k) {
            dp[j][k] = dp[j][k-1];
            currentSum = (currentSum + dp[j][k]) % N;
          }
          // length == 1
          // add N for negative case
          dp[j][1] = (total - sum[j] + N) % N;
          sum[j] = (currentSum + dp[j][1]) % N;
          currentTotal = (currentTotal + sum[j]) % N;
        }
        total = currentTotal;
      }

      return total;
    }
};

int main() {
  Solution solution;
  // vector<int> rollMax = {1,1,1,1,1,1};
  // vector<int> rollMax = {1,1,1,2,2,3};
  vector<int> rollMax = { 8,5,10,8,7,2 };
  cout << solution.dieSimulator(20, rollMax) << endl;
  return 0;
}
