/**
 *
 * Sean
 * 2016-05-06
 *
 * https://leetcode.com/problems/find-peak-element/
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 * Note:
 * Your solution should be in logarithmic complexity.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 *
 * Observation: peak must be in range x1~xk: beg, x1, x2, ... xk, end, where beg and end are smaller than any xi.
 * Invariant: the peak must be in range [begin, end].
 *
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1);
    }
private:
    int binarySearch(vector<int> &nums, int begin, int end) {
        if (begin == end)
            return begin;
        int mid = (begin+end)>>1;
        if (nums[mid] > nums[mid+1])
            return binarySearch(nums, begin, mid);
        else
            return binarySearch(nums, mid+1, end);
    }
};

int main() {
    vector<int> nums = {1,2,4,3};
    Solution solution;
    cout << solution.findPeakElement(nums) << endl;
}
