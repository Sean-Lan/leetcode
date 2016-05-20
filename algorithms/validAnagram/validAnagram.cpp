/**
 *
 * Sean
 * 2016-05-20
 *
 * https://leetcode.com/problems/valid-anagram/
 *
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // O(n*log(n)): First sort, then compare.
        bool isAnagram_naive(string s, string t) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return (s == t);
        }

        // O(n): Use hash table, first count then compare.
        bool isAnagram(string s, string t) {
            if (s.size() != t.size())
                return false;
            int cnt[26] = { 0 };
            for (auto &c : s)
                ++cnt[c-'a'];
            for (auto &c : t) {
                --cnt[c-'a'];
                if (cnt[c-'a'] < 0)
                    return false;
            }

            for (auto &i : cnt) {
                if (i != 0)
                    return false;
            }
            return true;
        }
};

int main() {
}
