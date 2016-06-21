/**
 *
 * Sean
 * 2016-06-21
 *
 * https://leetcode.com/problems/wiggle-sort-ii/
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 *
 * Example:
 * (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
 * (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 *
 * Note:
 * You may assume all input has valid answer.
 *
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Reference to https://leetcode.com/discuss/77133/o-n-o-1-after-median-virtual-indexing
// And the proof is at https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return;
        auto midIt = nums.begin() + (n>>1);
        nth_element(nums.begin(), midIt, nums.end());
        int mid = *midIt;
        int i=0, j=0, k=n-1;
        int ii, jj, kk;
        while (j<=k) {
            ii = getIndex(i, n);
            jj = getIndex(j, n);
            kk = getIndex(k, n);
            if (nums[jj]>mid) {
                swap(nums[ii], nums[jj]);
                ++i; ++j;
            } else if (nums[jj]<mid) {
                swap(nums[jj], nums[kk]);
                --k;
            } else { // equal
                ++j;
            }
        }
    }
    inline int getIndex(int i, int n) {
        int half = n>>1;
        if (i < half)
            return i*2 + 1;
        else
            return (i-half)*2;
    }
};

int main() {
    vector<int> nums = { 4, 5, 5, 6 };
    Solution solution;

    for (int i=0; i<5; ++i) {
        cout << solution.getIndex(i, 5) << endl;
    }
}
