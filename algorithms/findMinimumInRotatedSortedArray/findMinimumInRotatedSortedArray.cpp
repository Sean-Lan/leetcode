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
        int n = nums.size();
        int lastNumber = nums[n-1];

        auto p = [&lastNumber, &nums] (int index) {
            return nums[index] <= lastNumber;
        };
        
        int start = 0, end = n-1, mid;
        while (start < end) {
            mid = start + (end-start)/2;
            if (p(mid)) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return nums[start];
    }
};

int main() {
    return 0;
}
