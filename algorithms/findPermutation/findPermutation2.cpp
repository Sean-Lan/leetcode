/**
 *
 * Sean
 * 2017-03-15
 *
 * https://leetcode.com/problems/find-permutation
 *
 * By now, you are given a secret signature consisting of character 'D' and 'I'. 'D' represents a decreasing relationship between two numbers, 'I' represents an increasing relationship between two numbers. And our secret signature was constructed by a special integer array, which contains uniquely all the different number from 1 to n (n is the length of the secret signature plus 1). For example, the secret signature "DI" can be constructed by array [2,1,3] or [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that can't represent the "DI" secret signature.
 *
 * On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n] could refer to the given secret signature in the input.
 *
 * Example 1:
 * Input: "I"
 * Output: [1,2]
 * Explanation: [1,2] is the only legal initial spectial string can construct secret signature "I", where the number 1 and 2 construct an increasing relationship.
 *
 * Example 2:
 * Input: "DI"
 * Output: [2,1,3]
 * Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI",
 *
 * but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
 *
 * Note:
 *
 * The input string will only contain the character 'D' and 'I'.
 * The length of input string is a positive integer and will not exceed 10,000
 */
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

// reference from https://discuss.leetcode.com/topic/76221/java-o-n-clean-solution-easy-to-understand
//
// O(n)
//
// For example, given IDIIDD we start with sorted sequence 1234567
// Then for each k continuous D starting at index i we need to reverse [i, i+k] portion of the sorted sequence.
//
// IDIIDD
// 1234567 // sorted
// 1324765 // answer
class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> res(n+1);
        iota(res.begin(), res.end(), 1);
        int beg;
        for (int i = 0; i<n; ++i) {
            if (s[i] == 'D') {
                 beg = i;
                 while (i < n && s[i] == 'D') ++i;
                 reverse(res.begin() + beg, res.begin() + i + 1);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
