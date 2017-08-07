/**
 *
 * Sean
 * 2017-08-07
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 *
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 *
 * Example 1:
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 *
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 *  +1-1+1+1+1 = 3
 *  +1+1-1+1+1 = 3
 *  +1+1+1-1+1 = 3
 *  +1+1+1+1-1 = 3
 *
 *  There are 5 ways to assign symbols to make the sum of nums be target 3.
 *  Note:
 *  The length of the given array is positive and will not exceed 20.
 *  The sum of elements in the given array will not exceed 1000.
 *  Your output answer is guaranteed to be fitted in a 32-bit integer.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// dp
// O(sum*n)
// dp[i][cumSum] means the number of ways to sum up to S, when starting from i-th number with sum `cumSum`
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2001, -1));

        function<int(int, int)> dfs = [&](int index, int sum) {
            if (dp[index][sum+1000] >= 0) {
                return dp[index][sum+1000];
            }

            if (index == n) {
                return dp[n][sum+1000] = (sum == S);
            }

            return dp[index][sum+1000] = dfs(index+1, sum + nums[index]) + dfs(index+1, sum - nums[index]);
        };

        dfs(0, 0);

        return dp[0][1000];
    }
};

int main() {
    return 0;
}
