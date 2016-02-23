/**
 *
 * Sean
 * 2016-02-23
 *
 * https://leetcode.com/problems/next-permutation/
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    private:
        void reverse(vector<int> &nums, int from, int to) {
            while (from < to)
                swap(nums[from++], nums[to--]);
        }
    public:
        void nextPermutation(vector<int> &nums) {
            if (nums.size() <=1)
                return;
            int i = nums.size()-1;
            int j;
            while (true) {
                --i;
                // find i s.t. nums[i] < nums[i+1]
                if (nums[i] < nums[i+1]) {
                    // find j s.t. a[i] < a[j]
                    j = nums.size();
                    while (!(nums[i]<nums[--j]));
                    swap(nums[i], nums[j]);
                    // reverse
                    reverse(nums, i+1, nums.size()-1);
                    break;
                }
                if (i==0) {
                    // nums is in desending order
                    reverse(nums, 0, nums.size()-1);
                    break;
                }
            }
        }
};

void printVec(vector<int> &nums) {
    for (auto &i : nums)
        cout << i << " ";
    cout << endl;
}

int main() {
    Solution s;
    vector<int> nums =  {1,2,3};
    s.nextPermutation(nums);
    printVec(nums);

    nums =  {3,2,1};
    s.nextPermutation(nums);
    printVec(nums);

    nums =  {1,1,5};
    s.nextPermutation(nums);
    printVec(nums);

    nums =  {2,3,1};
    s.nextPermutation(nums);
    printVec(nums);
}

