/**
 *
 * Sean
 * 2016-09-29
 *
 * https://leetcode.com/problems/isomorphic-strings/
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 *
 */
#include <iostream>
#include <string>
using namespace std;

// compare whether the last position of current character is the same.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lastPositionS[256] = {0};
        int lastPositionT[256] = {0};
        int n = s.size();
        for (int i=0; i<n; ++i) {
            if (lastPositionS[s[i]+128] != lastPositionT[t[i]+128])
                return false;
            lastPositionS[s[i]+128] = i+1;
            lastPositionT[t[i]+128] = i+1;
        }
        return true;
    }
};

int main() {}
