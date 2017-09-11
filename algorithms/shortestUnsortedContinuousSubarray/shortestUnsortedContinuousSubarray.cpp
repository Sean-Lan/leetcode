/**
 *
 * Sean
 * 2017-09-11
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 * Note:
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means <=.
 *
 */
#include <vector>
using namespace std;

// O(n)
// from left to right, keep updating the maxSofar, if a number is less than maxSofar, it must be an out of order number
// from right to left, keep updating the minSofar, if a number is greater than minSofar, it must be an out of order number
// the number between the two is the subarray out of order
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSofar = nums.front();
        int e = -1;
        for (int i=1; i<n; ++i) {
            maxSofar = max(maxSofar, nums[i]);
            if (nums[i] < maxSofar) e = i;
        }

        if (e == -1) return 0;

        int minSofar = nums.back();
        int s = -1;
        for (int i=n-2; i>=0; --i) {
            minSofar = min(minSofar, nums[i]);
            if (nums[i] > minSofar) s = i;
        }

        return e-s+1;
    }
};

int main() {
    return 0;
}
