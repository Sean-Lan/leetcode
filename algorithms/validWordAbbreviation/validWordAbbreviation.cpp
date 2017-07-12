/**
 *
 * Sean
 * 2017-07-12
 *
 * https://leetcode.com/problems/valid-word-abbreviation/#/description
 *
 * Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.
 *
 * A string such as "word" contains only the following valid abbreviations:
 *
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 * Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
 *
 * Note:
 * Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.
 *
 * Example 1:
 * Given s = "internationalization", abbr = "i12iz4n":
 *
 * Return true.
 * Example 2:
 * Given s = "apple", abbr = "a2e":
 *
 * Return false.
 *
 */
#include <string>
#include <cctype>
using namespace std;

// O(n + m), simple string comparing, just be careful with some corner cases
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size();
        int m = abbr.size();

        int i=0, j=0;
        int cnt = 0;
        while (i<n && j<m) {
            while (isdigit(abbr[j])) {
                // number like "01" is not allowed
                if (cnt == 0 && abbr[j] == '0') return false;
                cnt = 10 * cnt + abbr[j] - '0';
                ++j;
            }
            if (cnt) {
                i += cnt;
                cnt = 0;
            }

            // safe check for bound-crossing
            if (i >= n && j>= m) break;
            if (word[i] != abbr[j]) return false;
            ++i;
            ++j;
        }

        return i == n && j == m;
    }
};

int main() {
    return 0;
}
