/**
 *
 * Sean
 * 2016-06-02
 *
 * https://leetcode.com/problems/count-of-range-sum/
 *
 * Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * A naive algorithm of O(n2) is trivial. You MUST do better than that.
 *
 * Example:
 * Given nums = [-2, 5, -1], lower = -2, upper = 2,
 * Return 3.
 * The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
 *
 */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// Use merge sort.
// O(n*log(n))
// Note: the sum of integers may overflow, so be careful.
class Solution {
public:
    int countWithMergeSort(vector<long long> &sums, int start, int end, int lower, int upper) {
        if (start == end) {
            return sums[start] >= lower && sums[start] <= upper;
        }
        int total = 0;
        int mid = (start+end) >> 1;
        total += countWithMergeSort(sums, start, mid, lower, upper);
        total += countWithMergeSort(sums, mid+1, end, lower, upper);

        // merge
        int i=start, j=mid+1, k=mid+1;
        for (; i<=mid; ++i) {
            while (j<=end && sums[j]-sums[i]<lower) ++j;
            while (k<=end && sums[k]-sums[i]<=upper) ++k;
            total += k-j;
        }

        vector<long long> firstPart(sums.begin()+start, sums.begin()+mid+1);
        vector<long long> secondPart(sums.begin()+mid+1, sums.begin()+end+1);
        int size1 = firstPart.size();
        int size2 = secondPart.size();

        i=0, j=0, k=start;
        while (i<size1 && j<size2) {
            if (firstPart[i] <= secondPart[j]) {
                sums[k++] = firstPart[i++];
            } else {
                sums[k++] = secondPart[j++];
            }
        }

        while (i<size1)
            sums[k++] = firstPart[i++];

        while (j<size2)
            sums[k++] = secondPart[j++];
        return total;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty() || lower>upper) return 0;
        int size = nums.size();
        vector<long long> sums(size+1, 0);
        for (int i=0; i<nums.size(); ++i)
            sums[i+1] = sums[i] + nums[i];
        return countWithMergeSort(sums, 1, nums.size(), lower, upper);
    }
};




int main() {
    Solution solution;
    vector<int> nums {-2147483647,0,-2147483647,2147483647};
    int lower = -564, upper = 3864;
    cout << solution.countRangeSum(nums, lower, upper) << endl;
}
