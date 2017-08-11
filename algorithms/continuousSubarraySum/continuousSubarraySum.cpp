/**
 *
 * Sean
 * 2017-08-11
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.
 *
 * Example 1:
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
 * Example 2:
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
 *
 * Note:
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
 *
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        if (k == 0) {
            for (int i=1; i<n; ++i) {
                if (nums[i] == 0 && nums[i-1] == 0) return true;
            }
            return false;
        }

        // store first shown index of cumSum % k
        unordered_map<int, int> table;
        table[0] = -1;
        int cumSum = 0;
        int r;
        for (int i=0; i<n; ++i) {
            cumSum += nums[i];
            r = cumSum % k;
            if (table.count(r)) {
                if (i-table[r] > 1) return true;
            } else {
                table[r] = i;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
