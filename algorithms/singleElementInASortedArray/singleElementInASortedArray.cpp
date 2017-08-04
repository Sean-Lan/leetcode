/**
 *
 * Sean
 * 2017-08-04
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.
 *
 * Example 1:
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 *
 * Example 2:
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * Note: Your solution should run in O(log n) time and O(1) space.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid;
        while (s < e) {
            mid = s + (e-s)/2;
            if (nums[mid] == nums[mid-1]) {
                if (mid & 1) // the first half has even numbers
                    s = mid + 1;
                else // the first half has odd numbers
                    e = mid - 2;
            } else if (nums[mid] == nums[mid+1]) {
                if (mid & 1) // the first half has even numbers
                    e = mid-1;
                else // the first half hsa odd numbers
                    s = mid + 2;
            } else {
                return nums[mid];
            }
        }
        return nums[s];
    }
};

int main() {
    return 0;
}
