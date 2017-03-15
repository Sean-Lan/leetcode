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
 * but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
 *
 * Note:
 *
 * The input string will only contain the character 'D' and 'I'.
 * The length of input string is a positive integer and will not exceed 10,000
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> res(n+1);
        res[0] = 1;
        char c;
        // insert the new number into the right place
        // the proof is easy:
        // assume we have k numbers has the optimal permutation P and we need to place k+1 into P
        // if we not take P, i.e, we insert k+1 into P' and obtain the optimal k+1 number permutation,
        // we can substitude P' with P, and since P and P' has the same secret signatue, the new k+1 number permutation
        // will be "more" optimal, which contradicts with the assumption, and here's the conclusion:
        // the k+1 number permutation must be obtained by insert k+1 into k optimal permutation
        //
        // The construction procedure is simple:
        // If the next secrect character is 'I', simply append k+1 to the end of the k number permutation,
        // If the next secrect character is 'D', insert k+1 to the begining of the trailing decreasing series of the k number permutation
        //
        // O(n^2)
        for (int i=1; i<=n; ++i) {
            c = s[i-1];
            if (c == 'I') {
                res[i] = i+1; 
            } else {
                int j=i-1;
                res[i] = res[j];
                while (j > 0 && res[j] < res[j-1]) {
                    res[j] = res[j-1];
                    -- j;
                }
                res[j] = i+1;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
