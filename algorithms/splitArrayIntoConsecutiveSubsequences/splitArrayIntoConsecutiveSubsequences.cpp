/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
 *
 * Example 1:
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences :
 * 1, 2, 3
 * 3, 4, 5
 *
 * Example 2:
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences :
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 *
 * Example 3:
 * Input: [1,2,3,4,4,5]
 * Output: False
 * Note:
 * The length of the input is in range of [1, 10000]
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n) time & space complexity
// greedy
//
// for a number x, there are two options:
// 1. append it to a sequence ending with x-1
// 2. start a new sequence with x
//
// if option 1 is feasible, we should take it since even if we start a new sequence from x,
// we could append it to a sequence ending with x-1
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto &num : nums) ++freq[num];

        // ending[x] means number of sequence ending with x
        unordered_map<int, int> ending;

        int cnt;
        for (auto &num : nums) {
            cnt = freq[num];
            if (cnt == 0) continue;
            if (ending[num-1] >= cnt) {
                ending[num] += cnt;
            } else {
                ending[num] += ending[num-1];
                cnt -= ending[num-1];
                if (freq[num+1] >= cnt && freq[num+2] >= cnt) {
                    freq[num+1] -= cnt;
                    freq[num+2] -= cnt;
                    ending[num+2] += cnt;
                } else {
                    return false;
                }
            }
            freq[num] = 0;
        }
        return true;
    }
};

int main() {
    return 0;
}
