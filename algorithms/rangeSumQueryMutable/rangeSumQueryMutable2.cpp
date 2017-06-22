/**
 *
 * Sean
 * 2017-06-22
 *
 * https://leetcode.com/problems/range-sum-query-mutable/#/description
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i to val.
 *
 * Example:
 *
 * Given nums = [1, 3, 5]
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 *
 * Note:
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed evenly.
 *
 */
#include <iostream>
#include <vector>

using namespace std;

// Binary Indexed Tree, refer to https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
class NumArray {
    int n;
    vector<int> BIT;
    vector<int> nums;

    int getSum(int i) {
        int sum = 0;
        while (i) {
            sum += BIT[i];
            i -= (i&-i);
        }
        return sum;
    }

public:
    NumArray(vector<int> nums) {
        this->n = nums.size();
        this->BIT = vector<int>(n+1, 0);
        this->nums = nums;

        for (int i=0; i<n; ++i) {
            int idx = i+1;
            BIT[idx] += nums[i];
            for (int j=idx-(idx&-idx)+1; j<idx; ++j) {
                BIT[idx] += nums[j-1];
            }
        }
    }

    void update(int i, int val) {
        int delta = val - nums[i];
        nums[i] = val;
        int idx = i+1;
        while (idx<=n) {
            BIT[idx] += delta;
            idx += (idx&-idx);
        }
    }

    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
    return 0;
}
