/**
 * 
 * Sean
 * 2020-04-06
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity 
 * should be O(log (m+n)).
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if ((m + n) & 1) {
            return findKth(nums1, nums2, 0, 0, (m+n+1)/2);
        } else {
            return (findKth(nums1, nums2, 0, 0, (m+n)/2) +
                    findKth(nums1, nums2, 0, 0, (m+n)/2+1))/2.0;
        }
    }

    int findKth(vector<int>& nums1, vector<int>& nums2, int i, int j, int k) {
        int m = nums1.size();
        int n = nums2.size();

        if (i == m) return nums2[j+k-1];

        // make sure remaining elements of nums1 is less than remaining elements nums2.
        if (m - i > n - j) {
            return findKth(nums2, nums1, j, i, k);
        }

        // special check for kk, make sure both r1 and r2 > 0.
        if (k == 1) return min(nums1[i], nums2[j]);

        int r1 = min(m-i, k/2);
        int r2 = k - r1;

        assert(r1 > 0);
        assert(r2 > 0);
        int v1 = nums1[i+r1-1];
        int v2 = nums2[j+r2-1];

        if (v1 > v2) {
            return findKth(nums1, nums2, i, j+r2, r1);
        } else if (v2 > v1) {
            return findKth(nums1, nums2, i+r1, j, r2);
        }

        return v1;
    }
};

int main() {
  return 0;
}
