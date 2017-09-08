/**
 *
 * Sean
 * 2017-09-08
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
 *
 * Example 1:
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 * Example 2:
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 *
 * Note:
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// sliding window, O(n)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (n < m) return false;

        vector<int> cnts(26, 0);
        for (auto &c : s1) ++ cnts[c-'a'];

        auto allZero = [&]() {
            for (auto &cnt : cnts) if (cnt) return false;
            return true;
        };

        for (int i=0; i<m; ++i) --cnts[s2[i]-'a'];

        if (allZero()) return true;

        for (int i=m; i<n; ++i) {
            ++cnts[s2[i-m]-'a'];
            --cnts[s2[i]-'a'];
            if (allZero()) return true;
        }

        return false;
    }
};

int main() {
    return 0;
}
