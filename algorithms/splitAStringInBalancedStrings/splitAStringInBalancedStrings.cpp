/**
 *
 * Sean
 * 2019-10-22
 *
 * https://leetcode.com/problems/split-a-string-in-balanced-strings/
 *
 * Balanced strings are those who have equal quantity of 'L' and 'R' characters.
 *
 * Given a balanced string s split it in the maximum amount of balanced strings.
 *
 * Return the maximum amount of splitted balanced strings.
 *
 * Example 1:
 *
 * Input: s = "RLRRLLRLRL"
 * Output: 4
 * Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
 * Example 2:
 *
 * Input: s = "RLLLLRRRLR"
 * Output: 3
 * Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
 * Example 3:
 *
 * Input: s = "LLLLRRRR"
 * Output: 1
 * Explanation: s can be split into "LLLLRRRR".
 *
 * Constraints:
 *
 * 1 <= s.length <= 1000
 * s[i] = 'L' or 'R'
 *
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int balancedStringSplit(string s) {
      int cnt = 0;
      int diff = 0;
      for (char c : s) {
        if (c == 'R') {
          ++ diff;
        } else {
          -- diff;
        }
        if (diff == 0) {
          ++cnt;
        }
      }

      return cnt;
    }
};

int main() {
  Solution solution;
  string s = "RLLLLRRRLR";
  cout << solution.balancedStringSplit(s) << endl;
  return 0;
}
