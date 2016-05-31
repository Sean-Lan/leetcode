/**
 *
 * Sean
 * 2016-05-30
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 *
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 *
 * click to show more practice.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// Using sliding window.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int start = 0, end = 0;
        int curSum = nums[0];
        int minL = INT_MAX;
        int size = nums.size();
        while (true) {
            if (curSum < s) {
                ++end;
                if (end == size) break;
                curSum += nums[end];
            } else {
                minL = min(minL, end-start+1);
                curSum -= nums[start];
                ++start;
                if (start > end) break;
            }
        }
        return minL==INT_MAX?0:minL;
    }
};

int main() {}
