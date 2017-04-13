/**
 *
 * Sean
 * 2017-04-13
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 *
 */
#include <vector>
#include <functional>
using namespace std;

// binary search
// get the proper partition of the two arrays
class Solution {
    int binarySearch(int s, int e, function<bool(int)> f) {
        int m;
        while (s < e) {
            m = s + (e-s)/2;
            if(f(m)) {
                e = m;
            } else {
                s = m+1;
            }
        }
        return s;
    }

    int getLeft(vector<int> &nums, int i) {
        if (i-1>=0) return nums[i-1];
        return INT_MIN;
    }

    int getRight(vector<int> &nums, int i) {
        if (i>=nums.size()) return INT_MAX;
        return nums[i];
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int k = (m+n)/2;

        int i = binarySearch(max(0, k-n), min(k, m), [&](int x) {
            return getRight(nums1, x) >= getLeft(nums2, k-x);
        });
        int j = k-i;
        int right =  min(getRight(nums1, i), getRight(nums2, j));
        if (m+n & 1) return right;
        int left = max(getLeft(nums1, i), getLeft(nums2, j));
        return (left+right)/2.0;
    }
};

int main() {
    return 0;
}
