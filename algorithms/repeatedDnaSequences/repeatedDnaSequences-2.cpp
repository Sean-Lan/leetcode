/**
 *
 * Sean
 * 2016-09-13
 *
 * https://leetcode.com/problems/repeated-dna-sequences/
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 *
 * For example,
 *
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 *
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// map 10 character string into a 4-byte integer.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_set<int> words;
        unordered_set<int> doubleWords;
        vector<string> result;
        int charMap[26];
        charMap['A'-'A'] = 0;
        charMap['C'-'A'] = 1;
        charMap['G'-'A'] = 2;
        charMap['T'-'A'] = 3;
        for (int i=0; i<s.size()-9; ++i) {
            int v = 0;
            for (int j=0; j<10; ++j) {
                v <<= 2;
                v |= charMap[s[i+j]-'A'];
            }
            if (!words.insert(v).second && !doubleWords.count(v)) {
                doubleWords.insert(v);
                result.push_back(s.substr(i, 10));
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    auto result = solution.findRepeatedDnaSequences("AAAAAAAAAAA");
    for (auto &s : result) {
        cout << s << endl;
    }
}
