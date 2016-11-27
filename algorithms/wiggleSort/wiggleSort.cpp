/**
 *
 * Sean
 * 2016-11-27
 *
 * https://leetcode.com/problems/wiggle-sort/
 *
 * Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 *
 * For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 *
 */
#include <vector>
using namespace std;

// O(n), reference to https://discuss.leetcode.com/topic/23877/4-lines-o-n-c
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i=1; i<nums.size(); ++i) {
            if ( (i&1 && nums[i]<nums[i-1]) || (!(i&1) && nums[i] > nums[i-1] ))
                swap(nums[i], nums[i-1]);
        }
    }
};

int main() {
    return 0;
}
