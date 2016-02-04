/**
 *
 * Sean
 * 2016-02-04
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 *
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) return 0;
            vector<int>::iterator cur, next;
            cur = nums.begin();
            next = cur;
            while (next!=nums.end()) {
                if (*next == *cur) {
                    ++next;
                    continue;
                }
                ++cur;
                *cur = *next;
                ++next;
            }
            return distance(nums.begin(), cur)+1;
        }

        // or you can use stl unique.
        int removeDuplicates2(vector<int>& nums) {
            auto newEnd = unique(nums.begin(), nums.end());
            return distance(nums.begin(), newEnd);
        }
};

int main() {
    vector<int> nums = {};
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
}
