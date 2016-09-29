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
 */
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// normalize s and t to a string with first character start with 0.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapS;
        unordered_map<char, char> mapT;
        char cur = 0;
        for (auto &c : s) {
            if (mapS.count(c)) {
                c = mapS[c];
            } else {
                mapS[c] = cur;
                c = cur++;
            }
        }
        
        cur = 0;
        for (auto &c : t) {
            if (mapT.count(c)) {
                c = mapT[c];
            } else {
                mapT[c] = cur;
                c = cur++;
            }
        }
        
        return s == t;
    }
};

int main() {}
