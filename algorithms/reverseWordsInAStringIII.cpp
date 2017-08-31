/**
 *
 * Sean
 * 2017-08-31
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 *
 */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// O(n) time complexity and O(1) space complexity
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        int n = s.size();
        int i = 0, j = 0;
        while (i < n) {
            while (isspace(s[i])) ++i;
            if (i == n) break;
            j = i+1;
            while (j<n && !isspace(s[j])) ++j;

            reverse(s.begin()+i, s.begin()+j);
            i = j;
        }
        return s;
    }
};

int main() {
    return 0;
}
