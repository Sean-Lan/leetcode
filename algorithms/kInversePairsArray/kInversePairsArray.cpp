/**
 *
 * Sean
 * 2017-07-03
 *
 * https://leetcode.com/problems/k-inverse-pairs-array/#/description
 *
 * Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.
 *
 * We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.
 *
 * Since the answer may very large, the answer should be modulo 109 + 7.
 *
 * Example 1:
 * Input: n = 3, k = 0
 * Output: 1
 * Explanation: 
 * Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
 *
 * Example 2:
 * Input: n = 3, k = 1
 * Output: 2
 * Explanation: 
 * The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 *
 * Note:
 * The integer n is in the range [1, 1000] and k is in the range [0, 1000].
 *
 */
#include <vector>
#include <iostream>
using namespace std;

static const int N = 1000000007;

// DP
// O(n * k) time complexity and O(k) space complexity
//
// dp[i][j] means the number of permutation with 1..i numbers containing k inverse pairs
// if we have dp[i-1][x], x >= 0 && x <= (i-1)*(i-2)/2, we could insert number i to the right place to create a new perm with j inverse pairs
// dp[i][j] = dp[i-1][lower] + dp[i-1][lower+1] + .. + dp[i-1][upper], where:
//  lower = max(j - (i-1), 0), because insert i into the perm with 1..i-1 will create i-1 inverse pairs at most
//  upper = min(j, (i-1)*(i-2)/2), because perm with 1..i-1 will have at most (i-1)*(i-2)/2 inverser pairs
//
//  the optimization:
//
//  1. since we need to calculate the continuous sum, we can use cumulative sum to get continuous sum in O(1) time complexity
//  2. once we have cumulative sum array, the orginial dp array is not needed, all the information for calculating next value can be obtained from the cumulative array
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) return 1;
        if (k > n*(n-1)/2) return 0;
        
        int dp = 1;
        
        vector<int> cumSum1(k+1, 0);
        vector<int> cumSum2(k+1, 0);
        cumSum1[0] = cumSum2[0] = 1;
        
        for (int i = 2; i<=n; ++i) {
            int maxVal = min(i * (i-1) / 2, k);
            for (int j = 1; j<=maxVal; ++j) {
                int upper = min(j, (i-1)*(i-2)/2);
                int lower = max(j - (i-1), 0);
                
                if (lower == 0) dp = cumSum1[upper];
                else dp = cumSum1[upper] - cumSum1[lower-1];
                
                dp %= N;
                
                cumSum2[j] = cumSum2[j-1] + dp;
                cumSum2[j] %= N;
            }
            swap(cumSum1, cumSum2);
        }
        return dp < 0 ? dp + N : dp;
    }
};

int main() {
    return 0;
}
