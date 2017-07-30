/**
 *
 * Sean
 * 2017-07-30
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 *
 * Example 1:
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 * Note:
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 *
 */
#include <vector>
using namespace std;

// sliding window
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxSum = INT_MIN;

        int n = nums.size();
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i-k];
            }
            if (i >= k-1) {
                maxSum = max(maxSum, sum);
            }
        }

        return (double)maxSum/k;
    }
};

int main() {
    return 0;
}
