/**
 *
 * Sean
 * 2016-11-01
 *
 * https://leetcode.com/problems/split-array-largest-sum/
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
#include <vector>
using namespace std;

// binary search refering to https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/
class Solution {
    typedef long long ll;
public:
    int splitArray(vector<int>& nums, int m) {
        int maxValue = 0;
        ll sum = 0;
        for (auto &i : nums) {
            maxValue = max(maxValue, i);
            sum += i;
        }

        ll start = maxValue;
        ll end = sum;
        ll mid;

        auto p = [&nums, m] (ll value) {
           ll tmpSum = 0;
           int cnt = 1;
           for (auto &i : nums) {
               if (tmpSum + i <= value) {
                   tmpSum += i;
               } else {
                   tmpSum = i;
                   ++cnt;
               }
           }
           return cnt <= m;
        };
        while (start < end) {
            mid = start + (end - start)/2;
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

