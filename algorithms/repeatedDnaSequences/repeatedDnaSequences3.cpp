/**
 *
 * Sean
 * 2017-08-23
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
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
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// rolling hash: https://en.wikipedia.org/wiki/Rolling_hash
static const uint32_t C = 1000000000;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        uint32_t table[26];
        table['A'-'A'] = 0; table['C'-'A'] = 1;
        table['G'-'A'] = 2; table['T'-'A'] = 3;
        unordered_set<uint32_t> shown;
        uint32_t val = 0;
        int n = s.size();
        unordered_set<string> res;
        for (int i=0; i<n; ++i) {
            if (i >= 10) val -= table[s[i-10]-'A'] * C;
            val *= 10;
            val += table[s[i]-'A'];
            if (i >= 9) {
                if (shown.count(val)) res.insert(s.substr(i-9, 10));
                shown.insert(val);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};

int main() {
    return 0;
}
