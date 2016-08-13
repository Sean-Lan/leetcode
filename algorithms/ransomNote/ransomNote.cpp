/**
 *
 * Sean
 * 2016-08-13
 *
 * https://leetcode.com/problems/ransom-note/
 *
 *  Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines; otherwise, it will return false.   
 *
 * Each letter in the magazine string can only be used once in your ransom note.
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 */
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> noteCnt, magazineCnt;
        for (auto c : ransomNote)
            ++noteCnt[c];

        for (auto c : magazine)
            ++magazineCnt[c];

        for (auto c : ransomNote)
            if (magazineCnt[c] < noteCnt[c])
                return false;

        return true;
    }
};

int main() {
    string ransomNote = "a";
    string magazine = "b";
    Solution solution;
    cout << solution.canConstruct(ransomNote, magazine) << endl;
    return 0;
}
