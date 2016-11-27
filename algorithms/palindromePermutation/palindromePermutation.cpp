/**
 *
 * Sean
 * 2016-11-27
 *
 * https://leetcode.com/problems/palindrome-permutation/
 *
 * Given a string, determine if a permutation of the string could form a palindrome.
 *
 * For example,
 * "code" -> False, "aab" -> True, "carerac" -> True.
 *
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<char, int> table;
public:
    bool canPermutePalindrome(string s) {
        for (auto &c : s) ++table[c];
        bool hasOdd = false;
        for (auto &aPair : table) {
            if (aPair.second & 1) {
                if (hasOdd) return false;
                hasOdd = true;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
