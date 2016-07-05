/**
 *
 * Sean
 * 2016-07-05
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Using an hash table to keep the consecutive number length.
// Remember to update the two end of the range.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int maxLen = 0;
        int left, right, sum;
        for (auto &i : nums) {
            if (!cnts.count(i)) {
                left = cnts.count(i-1) ? cnts[i-1] : 0;
                right = cnts.count(i+1) ? cnts[i+1] : 0;
                sum = left + right + 1;
                maxLen = max(maxLen, sum);
                cnts[i] = sum;
                // update the two end of the range
                if (left) cnts[i-left] = sum;
                if (right) cnts[i+right] = sum;
            }
        }
        return maxLen;
    }
};

int main() {}
