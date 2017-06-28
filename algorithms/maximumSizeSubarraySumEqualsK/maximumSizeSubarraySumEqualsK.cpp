/**
 *
 * Sean
 * 2017-06-28
 *
 * https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/#/description
 *
 * Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
 *
 * Note:
 * The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
 *
 * Example 1:
 * Given nums = [1, -1, 5, -2, 3], k = 3,
 * return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
 *
 * Example 2:
 * Given nums = [-2, -1, 2, 1], k = 1,
 * return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
 *
 * Follow Up:
 * Can you do it in O(n) time?
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;

// use a hashtable to store the mapping from the prefix sum to the smallest i
// for each cumulative sum, check whether sum-k exisits, if so, there'll be a subarray sums to k
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sumToIndex;
        int maxLen = 0;
        int sum = 0;
        int n = nums.size();

        sumToIndex[0] = -1;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            if (sumToIndex.count(sum - k)) {
                maxLen = max(maxLen, i - sumToIndex[sum-k]);
            }
            if (!sumToIndex.count(sum)) {
                sumToIndex[sum] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    return 0;
}
