/**
 * 
 * Sean
 * 2015-04-20
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
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
    public:
        typedef vector<int>::iterator VectIt;
        /**
         * The naive merge-then-sort method.
         */
        double findMedianSortedArrays_naive(vector<int>& nums1, vector<int>& nums2) {
            vector<int> merged;
            double median;
            copy(nums1.begin(), nums1.end(), back_inserter(merged));
            copy(nums2.begin(), nums2.end(), back_inserter(merged));
            sort(merged.begin(), merged.end());
            if (merged.size()%2) {
                median = merged[merged.size()/2]; 
            } else {
                median = (merged[merged.size()/2-1] + merged[merged.size()/2])/2.0;
            }
            return median;
        }
        /**
         * Take advantage of findKth member function:
         * If totalSize is even: return the average of the two median number,
         * else: just return the exactly center number.
         */
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int totalSize = nums1.size() + nums2.size();
            if (totalSize % 2)
                return *(findKth(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),totalSize/2 + 1));
            else
                return (*(findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), totalSize/2)) + 
                        *(findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), totalSize/2+1)))/2.0;
        }
    private:
        /**
         * 
         * Divide and conquer.
         * Every time half k into two parts, and cmp the k/2-th number of each vector.
         * If pivort1 < pivort2: the k/2 number in vector1 must not be the k-th number,
         *  and we can obsolete them.
         * Else if pivort1 < pivort2: obsolete k/2 number in vector2
         * Else: pivort1 == pivort2, either of the two if the k-th number we want.
         *
         */
        VectIt findKth(VectIt beg1, VectIt end1, VectIt beg2, VectIt end2, int k) {
            int size1 = distance(beg1, end1);
            int size2 = distance(beg2, end2);
            if (size1 > size2) // Make sure Vec2 is larger
                return findKth(beg2, end2, beg1, end1, k);
            if (beg1 == end1)
                return beg2 + k-1;
            if (k == 1)
                return *beg1 < *beg2 ? beg1 : beg2;  
            // divide k into two parts 
            int pa, pb;
            pa = min(k/2, size1);
            pb = k - pa; 
            VectIt pivot1 = beg1+pa-1, pivot2 = beg2+pb-1;
            if (*pivot1 < *pivot2)
                return findKth(beg1+pa, end1, beg2, end2, k-pa);
            else if (*pivot1 > *pivot2)
                return findKth(beg1, end1, beg2+pb, end2, k-pb);
            else
                return pivot1; 
        }
};

int main() {
    Solution solution;
    vector<int> nums1 = {};
    vector<int> nums2 = {2,3};
    cout << solution.findMedianSortedArrays(nums1,nums2) << endl;
}

