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

// Standard segment tree's heap implementation: refer to https://leetcode.com/articles/range-sum-query-mutable/
class NumArray {
    int n;
    vector<int> tree;
public:
    NumArray(vector<int> nums) {
        n = nums.size(); // head and tail needs to be reserved

        tree = vector<int>(n + n, 0);

        // update leaves
        for (int i=0; i<n; ++i)
            tree[n+i] = nums[i];

        // update non-leave nodes
        for (int i=n-1; i>0; --i)
            tree[i] = tree[i+i] + tree[i+i+1];

    }

    void update(int i, int val) {
        i += n;
        tree[i] = val;
        for (i >>= 1; i; i >>= 1)
            tree[i] = tree[i+i] + tree[i+i+1];
    }

    int sumRange(int i, int j) { // [i, j] inclusive
        int sum = 0;
        for (i = n+i, j = n+j; i <= j; i>>=1, j>>=1) {
            // if i is even, its sibling node should be also included
            // we should add its parent (or ancestor) later
            if (i&1) {
                sum += tree[i];
                ++i;
            }
            // if j is odd, its sibling node should be also included
            // we should add its parent (or ancestor) later
            if (!(j&1)) {
                sum += tree[j];
                --j;
            }
        }
        return sum;
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
