/**
 *
 * Sean
 * 2016-08-18
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 */
#include <vector>
using namespace std;

// binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = (int)nums.size()-1;
        int mid;
        // invariant: the minimum is in nums[start..end]
        while (start < end) {
            mid = (start+end)>>1;
            if (nums[mid] < nums[end])
                end = mid;
            else
                start = mid+1;
        }
        return nums[start];
    }
};

int main() {
    return 0;
}
