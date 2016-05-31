/**
 *
 * Sean
 * 2016-05-31
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


// first calculate the cumlative sum of nums, then perform binary search for n times.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int size = nums.size();
        vector<int> sum(size, 0);
        sum[0] = nums[0];
        for (int i=1; i<size; ++i) {
            sum[i] = sum[i-1] + nums[i];
        }

        int minL = INT_MAX;
        int end = size -1;
        int startSum;
        for (int start = 0; start<size; ++start) {
            if (start == 0)
                startSum = 0;
            else
                startSum = sum[start-1];
            int pos = firstGreaterOrEqual(start, end, s, sum, startSum);
            if (pos != -1)
                minL = min(minL, pos-start+1);
        }

        return minL==INT_MAX?0:minL;

    }

    int firstGreaterOrEqual(int start, int end, int val, vector<int>& sum, int startSum) {
        int mid;
        while (start <= end) {
            if (start == end) {
                if (sum[start]-startSum >= val)
                    return start;
                break;
            }
            mid = (start+end) >> 1;
            if (sum[mid]-startSum < val) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return -1;
    }
};

int main() {}
