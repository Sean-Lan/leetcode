/**
 *
 * Sean
 * 2016-02-27
 * https://leetcode.com/problems/search-insert-position/
 *
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// It's better use the STL lower_bound() directly.
class Solution {
    typedef vector<int>::iterator IT;
    IT insertPosition(IT first, IT last, const int &target) {
        int count = last -first;
        int step;
        IT it;
        while (count>0) {
            step = count>>1;
            it = first+step;
            if (*it < target) {
                first = ++it;
                count -= step+1;
            } else
                count = step;
        }
        return first;
    }

    public:
        int searchInsert(vector<int> &nums, int target) {
            return insertPosition(nums.begin(), nums.end(), target) - nums.begin();
        }
};

int main() {
    Solution solution;
    vector<int> nums = {1,3,5,6};
    cout << solution.searchInsert(nums, 0) << endl;
}
