/**
 *
 * Sean
 * 2020-03-30
 *
 * https://leetcode.com/problems/count-number-of-teams/
 *
 * There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
 *
 * You have to form a team of 3 soldiers amongst them under the following rules:
 *
 * Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
 * A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k])
 * where (0 <= i < j < k < n).
 * Return the number of teams you can form given the conditions.
 * (soldiers can be part of multiple teams).
 *
 * Example 1:
 *
 * Input: rating = [2,5,3,4,1]
 * Output: 3
 * Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).
 * Example 2:
 *
 * Input: rating = [2,1,3]
 * Output: 0
 * Explanation: We can't form any team given the conditions.
 * Example 3:
 *
 * Input: rating = [1,2,3,4]
 * Output: 4
 *
 * Constraints:
 *
 * n == rating.length
 * 1 <= n <= 200
 * 1 <= rating[i] <= 10^5
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // O(n^3)
    int numTeams_On3(vector<int>& rating) {
      int n = rating.size();
      if (n < 3) return 0;

      int cnt = 0;

      for (int i = 0; i< n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
          int ri = rating[i];
          int rj = rating[j];
          if (ri == rj) continue;
          bool ascending = ri < rj;
          for (int k = j+1; k < n; ++k) {
            if ((ascending && (rating[k] > rj)) ||
                (!ascending && (rating[k] < rj))) ++cnt;
          }
        }
      }

      return cnt;
    }

    // O(n^2)
    int numTeams(vector<int>& rating) {
      int n = rating.size();

      if (n < 3) return 0;

      vector<int> leftLess(n, 0);
      vector<int> leftGreater(n, 0);
      vector<int> rightLess(n, 0);
      vector<int> rightGreater(n, 0);

      for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
          if (rating[i] < rating[j]) {
            ++ leftLess[j];
            ++ rightGreater[i];
          }
          if (rating[i] > rating[j]) {
            ++ rightLess[i];
            ++ leftGreater[j];
          }
        }
      }

      int cnt = 0;
      for (int i=1; i<n; ++i) {
        cnt += leftLess[i] * rightGreater[i] + leftGreater[i] * rightLess[i];
      }
      return cnt;
    }
};

int main() {
  vector<int> rating = {2,5,3,4,1};
  Solution solution = Solution();

  int cnt = solution.numTeams(rating);
  cout << cnt << endl;

  return 0;
}
