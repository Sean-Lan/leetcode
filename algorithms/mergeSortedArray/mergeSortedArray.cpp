/**
 *
 * Sean
 * 2016-03-14
 *
 * https://leetcode.com/problems/merge-sorted-array/
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// next points to the next position a number should be inserted from the end.
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int next = m+n-1;
            int i=m-1, j=n-1;
            int num1, num2;
            while (i>=0 && j>=0) {
                num1 = nums1[i];
                num2 = nums2[j];
                if (num1 > num2) {
                    nums1[next--] = num1;
                    --i;
                } else {
                    nums1[next--] = num2;
                    --j;
                }
            }
            while (j>=0)
                nums1[next--] = nums2[j--];
        }
};

int main() {
}
