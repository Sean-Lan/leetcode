/**
 *
 * Sean
 * 2017-07-29
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
 *
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.
 *
 * Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 *
 * Note:
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 *
 * Example 1:
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
 *
 * Example 2:
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
 *
 */
#include <vector>
#include <string>
using namespace std;

// 2D knapsack
class Solution {
    pair<int, int> get01(const string& s) {
        int c0=0, c1=0;
        for (auto c : s) {
            if (c == '0') ++c0;
            else ++ c1;
        }
        return {c0, c1};
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<pair<int, int>> zos(sz);
        for (int i=0; i<sz; ++i) {
            zos[i] = get01(strs[i]);
        }

        // dp[i][j]: with i zeros and j ones spent, how many strings can be obtained
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int c0, c1;
        for (auto &p : zos) {
            c0 = p.first;
            c1 = p.second;

            for (int i=m; i>=c0; --i) {
                for (int j=n; j>=c1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-c0][j-c1]+1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    return 0;
}
