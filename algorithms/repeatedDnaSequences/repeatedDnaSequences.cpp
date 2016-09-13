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
#include <unordered_map>
using namespace std;

// use hash map
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<string, int> table;
        for (int start=0; start<s.size()-9; ++start) {
            ++table[s.substr(start, 10)];
        }
        vector<string> result;
        for (auto &aPair : table) {
            if (aPair.second > 1)
                result.push_back(aPair.first);
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
