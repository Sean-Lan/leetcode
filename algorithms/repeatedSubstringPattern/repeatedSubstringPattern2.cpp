/**
 *
 * Sean
 * 2016-11-18
 *
 * https://leetcode.com/problems/repeated-substring-pattern/
 *
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 *
 * Example 1:
 * Input: "abab"
 *
 * Output: True
 *
 * Explanation: It's the substring "ab" twice.
 * Example 2:
 * Input: "aba"
 *
 * Output: False
 * Example 3:
 * Input: "abcabcabcabc"
 *
 * Output: True
 *
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O(n)
class Solution {
    // KMP prefix table, table[i] means the maximum characters common in header and tail.
    // One exeption: If the sting comprises of all the same characters, table[n-1] = n-1.
    vector<int> prefixTable(const string &str) {
        int n = str.size();
        vector<int> table(n, 0);
        int pos = 1;
        int i = 0;
        while (pos < n) {
            if (str[pos] == str[i]) {
                table[pos] = i + 1;
                ++pos;
                ++i;
            } else  if (i > 0) {
                i = table[i-1];
            } else {
                table[pos] = 0;
                ++pos;
            }
        }
        return table;
    }

public:
    bool repeatedSubstringPattern(string str) {
        vector<int> table = prefixTable(str);
        int n = str.size();
        int len = table[n-1];
        return (len && n % (n-len) == 0);
    }
};

int main() {
    Solution solution;
    cout << solution.repeatedSubstringPattern("abababaaba") << endl;
    return 0;
}

