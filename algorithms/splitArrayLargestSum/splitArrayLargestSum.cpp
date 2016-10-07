/**
 *
 * Sean
 * 2016-10-07
 *
 * Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
 *
 * Note:
 * Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.
 *
 * Examples:
 *
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 *
 * Output:
 * 18
 *
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Binary search
// Reference to https://discuss.leetcode.com/topic/61314/binary-search-c-solution
class Solution {
    typedef long long ll;
    bool canSplit(vector<int>& nums, int m, int value) {
        int s = 0;
        int cnt = 1;
        for (auto &i : nums) {
            s += i;
            if (s > value) {
                s = i;
                ++cnt;
            }
        }
        return cnt <= m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        ll right = 0;
        for (auto &i : nums) {
            left = max(left, i);
            right += i;
        }
        ll mid;
        while (left < right) {
            mid = (left+right)>>1;
            if (canSplit(nums, m, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};

int main() {}
