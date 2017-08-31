/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/split-array-with-equal-sum/description/
 *
 * Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:
 *
 * 0 < i, i + 1 < j, j + 1 < k < n - 1
 * Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
 * where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
 *
 * Example:
 * Input: [1,2,1,2,1,2,1]
 * Output: True
 * Explanation:
 * i = 1, j = 3, k = 5.
 * sum(0, i - 1) = sum(0, 0) = 1
 * sum(i + 1, j - 1) = sum(2, 2) = 1
 * sum(j + 1, k - 1) = sum(4, 4) = 1
 * sum(k + 1, n - 1) = sum(6, 6) = 1
 * Note:
 * 1 <= n <= 2000.
 * Elements in the given array will be in range [-1,000,000, 1,000,000].
 *
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


// O(n^2) time complexity and O(n) space complexity
// 1. locate j and split the array into two halves
// 2. from the first half, locate all the possible i, add all possible part sum into a hash table
// 3. from the second half, locate all the possible k, check whether the section sum shows in the hash table of step2
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;

        vector<int> cumSum(n, 0);
        cumSum[0] = nums[0];
        for (int i=1; i<n; ++i) cumSum[i] = cumSum[i-1] + nums[i];

        for (int j=3; j<n-3; ++j) {
            unordered_set<int> table;
            for (int i=1; i<j-1; ++i) {
                if (cumSum[i-1] == cumSum[j-1] - cumSum[i]) table.insert(cumSum[i-1]);
            }
            if (table.empty()) continue;
            for (int k=j+2; k<n-1; ++k) {
                int sum = cumSum[k-1] - cumSum[j];
                if (sum == cumSum[n-1] - cumSum[k] && table.count(sum)) return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
