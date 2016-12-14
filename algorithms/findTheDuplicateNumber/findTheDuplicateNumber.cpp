/**
 *
 * Sean
 * 2016-12-14
 *
 * https://leetcode.com/problems/find-the-duplicate-number/
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *
 */
#include <algorithm>
#include <vector>
using namespace std;

// value range based binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto aPair= minmax_element(nums.begin(), nums.end());
        int start = *aPair.first, end = *aPair.second, mid;

        // FFFFTTTT find first T
        auto p = [&nums] (int val) {
            int cnt =0;
            for (auto &i : nums) {
                if (i <= val) ++cnt;
            }
            return cnt > val;
        };
        
        while (start < end) {
            mid = start + (end-start)/2;
            if (p(mid)) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
};

int main() {
    return 0;
}
