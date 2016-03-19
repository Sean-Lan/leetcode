/**
 *
 * Sean
 * 2016-03-19
 *
 * https://leetcode.com/problems/maximum-subarray/
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n) solution.
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int maxSofar = nums[0];
            int maxEndingHere = nums[0];
            int size = nums.size();
            for (int i=1; i<nums.size(); ++i) {
                maxEndingHere = max(maxEndingHere+nums[i], nums[i]);
                maxSofar = max (maxSofar, maxEndingHere);
            }
            return maxSofar;
        }
};

int main() {}
