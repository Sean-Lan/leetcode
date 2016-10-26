/**
 *
 * Sean
 * 2016-10-26
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/
 *
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Sliding Window.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> result;
        int cnts[26] = {0};
        for (auto c : p) {
            ++cnts[c-'a'];
        }
        int m = p.size(), n = s.size();
        for (int i=0; i<m; ++i) {
            --cnts[s[i]-'a'];
        }
        // *Note*: `cnts` must be captured by reference, otherwise `cnts` is copied
        auto valid = [&cnts] {
            for (auto i : cnts) {
                if (i != 0) return false;
            }
            return true;
        };

        if (valid()) result.push_back(0);
        for (int i=m; i<n; ++i) {
            ++cnts[s[i-m]-'a'];
            --cnts[s[i]-'a'];
            if (valid()) result.push_back(i-m+1);
        }
        return result;
    }
};

int main() { return 0; }
