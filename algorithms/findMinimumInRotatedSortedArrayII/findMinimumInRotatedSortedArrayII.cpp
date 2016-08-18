/**
 *
 * Sean
 * 2016-08-18
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 *
 * Follow up for "Find Minimum in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 */
#include <vector>
using namespace std;

// worst case O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = (int)nums.size()-1;
        int mid;
        // invariant: the minimum is in nums[start..end]
        while (start < end) {
            mid = (start + end) >> 1;
            if (nums[mid] < nums[end])
                end = mid;
            else if (nums[mid] > nums[end])
                start = mid+1;
            else { // nums[mid] == nums[end]
                if (nums[mid] < nums[start]) {
                    end = mid;
                } else if (nums[mid] > nums[start]) {
                    end = mid-1;
                } else { // nums[mid] == nums[start]
                    while (start < end && nums[start] == nums[end])
                        ++start;
                }
            }
        }
        return nums[start];
    }
};

int main() {
    return 0;
}
