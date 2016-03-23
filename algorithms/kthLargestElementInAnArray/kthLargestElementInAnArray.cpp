/**
 *
 * Sean
 * 2016-03-23
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Similar to quick sort. First do the partition, then decide which part to coninue search.
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            return quickFind(0, nums.size()-1, nums, k);
        }
    private:
        int partition(int pivotIndex, int start, int end, vector<int> &nums) {
            int pivot = nums[pivotIndex];
            int i = start-1;
            for (int j=start; j<end; ++j) {
                if (nums[j]>pivot)
                    swap(nums[++i], nums[j]);
            }
            swap(nums[++i], nums[pivotIndex]);
            return i;
        }

        int quickFind(int start, int end, vector<int> &nums, const int &k) {
            int i = partition(end, start, end, nums);
            if (i<k-1)
                return quickFind(i+1, end, nums, k);
            if (i>k-1)
                return quickFind(start, i-1, nums, k);
            return nums[i];
        }
};

int main() {
    vector<int> nums = { 2,3,1,5,6,4 };
    Solution solution;
    cout << solution.findKthLargest(nums, 2) << endl;
}
