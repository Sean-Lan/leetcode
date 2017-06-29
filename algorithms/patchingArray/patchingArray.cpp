/**
 *
 * Sean
 * 2017-06-29
 *
 * https://leetcode.com/problems/patching-array/#/description
 *
 * Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
 *
 * Example 1:
 * nums = [1, 3], n = 6
 * Return 1.
 *
 * Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
 * Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
 * Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
 * So we only need 1 patch.
 *
 * Example 2:
 * nums = [1, 5, 10], n = 20
 * Return 2.
 * The two patches can be [2, 4].
 *
 * Example 3:
 * nums = [1, 2, 2], n = 5
 * Return 0.
 *
 */
#include <vector>
#include <iostream>

using namespace std;

// reference to https://discuss.leetcode.com/topic/35494/solution-explanation
// basic idea:
// invariant:
// any number in [0, miss) can be obtained through nums[0:i] (i not included) and patched numbers
//
// if we get a number, i.e, k, which <= miss, we can extend the number of range we can obtain to [0, miss+k)
// if we get a number k > miss, we cannot get [miss, k) from the numbers in nums, we need do a patch, and the best patch is add miss, because it
// extends the longest range to [miss, 2*miss)
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int cnt = 0;
        int i=0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                ++ cnt;
                miss += miss;
            }
        }
        return cnt;
    }
};

int main() {
    return 0;
}
