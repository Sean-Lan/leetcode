/**
 *
 * Sean
 * 2016-11-09
 *
 * https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 *
 * A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 *
 * For example, these are arithmetic sequences:
 *
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * The following sequence is not arithmetic.
 *
 * 1, 1, 2, 5, 7
 *
 * A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.
 *
 * A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.
 *
 * The function should return the number of arithmetic subsequence slices in the array A.
 *
 * The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.
 *
 *
 * Example:
 *
 * Input: [2, 4, 6, 8, 10]
 *
 * Output: 7
 *
 * Explanation:
 * All arithmetic subsequence slices are:
 * [2,4,6]
 * [4,6,8]
 * [6,8,10]
 * [2,4,6,8]
 * [4,6,8,10]
 * [2,4,6,8,10]
 * [2,6,10]
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    typedef long long ll;
public:
    // DP reference for vesion: https://discuss.leetcode.com/topic/66725/o-n-2-mle-tle-in-c-try-this-one-concise-and-fast
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<unordered_map<int, int>> dp(n);
        int res = 0;
        long long diff;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                diff = (ll)A[i]-A[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                ++ dp[i][diff];
                if (dp[j].count(diff)) {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> A {0,2000000000,-294967296};
    cout << solution.numberOfArithmeticSlices(A) << endl;
    return 0;
}
