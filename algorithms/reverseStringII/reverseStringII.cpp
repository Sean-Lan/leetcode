/**
 *
 * Sean
 * 2017-08-26
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
 *
 * Example:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Restrictions:
 * The string consists of lower English letters only.
 * Length of the given string and k will in the range [1, 10000]
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        int i;
        for (i=0; i+2*k<n; i+=2*k) {
            auto it1 = s.begin() + i;
            auto it2 = it1 + k;
            reverse(it1, it2);
        }

        if (i < n) {
            auto it1 = s.begin() + i;
            auto it2 = i+k < n ? it1 + k : s.end();
            reverse(it1, it2);
        }

        return s;
    }
};

int main() {
    return 0;
}
