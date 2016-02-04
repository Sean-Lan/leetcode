/**
 *
 * Sean
 * 2016-02-04
 *
 * https://leetcode.com/problems/remove-element/
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator cur, next;
        cur = nums.begin();
        next = cur;
        while (true) {
            // find next val
            while (cur!=nums.end() && *cur!=val) ++cur;
            if (cur == nums.end()) break;
            next = cur+1;

            // find next isn't equal to val
            while (next!=nums.end() && *next==val) ++next;
            if (next == nums.end()) break;
            *cur = *next;
            *next = val;
            ++cur;
        }
        return distance(nums.begin(), cur);
    }

    // or use stl remove
    int removeElement2(vector<int>& nums, int val) {
        vector<int>::iterator newEnd = remove(nums.begin(), nums.end(), val);
        return distance(nums.begin(), newEnd);
    }
};

int main() {
    vector<int> nums = {4,5};
    Solution s;
    cout << s.removeElement(nums, 4) << endl;
}
