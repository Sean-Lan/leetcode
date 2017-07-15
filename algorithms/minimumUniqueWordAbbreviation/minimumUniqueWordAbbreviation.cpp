/**
 *
 * Sean
 * 2017-07-15
 *
 * https://leetcode.com/problems/minimum-unique-word-abbreviation/#/description
 *
 * A string such as "word" contains the following abbreviations:
 *
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 * Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.
 *
 * Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.
 *
 * Note:
 * In the case of multiple answers as shown in the second example below, you may return any one of them.
 * Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
 * Examples:
 * "apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")
 *
 * "apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// an string abbreviation corresponds to a bit mask of 01 with the same length of the string in that:
//  if a character is remained, gets bit 1
//  else gets bit 0
// for example:
// s: apple
// abbr: a4, bit mask: 10000
// abbr: a1p1e, bit mask: 10101
//
// one abbr could apply to two word, if the two words have the same length and the remained characters are the same.
// e.g.
//  `app2` to `apple` and `apply`
// if we want to the abbr only apply to target, the characters remained in target abbr must differ from those of other words
// at the corresponding position
//
// There, we can get kind of `diffMask` of the words in the dictionary, in that:
//  if the corresponding characters are different, get bit 1
//  else gets bit 0
// e.g.
// `apply` to `apple`: 00011
//
// Now the problem transforms into find a bit mask that makes (mask & diffMask) != 0 for all words with the same length in the dictionary.
//
// One optimization is that, we only care the position that there are characters differ from `target`, so we could bitwise OR all the diffMasks
// and focus on the bits that're not 0.
class Solution {
    vector<int> possibleMasks;
    int n, possible;
    string target;
    string res;
    int minLength;

    string getAbbr(const string &target, int mask) {
        int cnt = 0;
        int n = target.size();
        string res;
        for (int i=0; i<n; ++i) {
            if (mask & (1<<i)) {
                if (cnt) {
                    res += to_string(cnt);
                    cnt = 0;
                }
                res += target[i];
            } else {
                ++ cnt;
            }
        }
        if (cnt) res += to_string(cnt);
        return res;
    }

    int getMask(const string &target, const string &s) {
        int n = target.size();
        int mask = 0;
        for (int i=0; i<n; ++i) {
            if (target[i] != s[i]) {
                mask |= (1 << i);
            }
        }
        return mask;
    }

    int getAbbrLength(int mask) {
        int len = 0;
        bool zero = false;
        for (int i=0; i<n; ++i) {
            if ((mask & (1<<i))) {
                ++len;
                zero = false;
            } else {
                if (!zero) {
                    zero = true;
                    ++len;
                }
            }
        }
        return len;
    }

    void dfs(int step, int cur) {
        if (step == n) {
            bool valid = true;
            int length = getAbbrLength(cur);
            if (length >= minLength) return;
            for (auto mask : possibleMasks) {
                if ((cur & mask) == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                minLength = length;
                res = getAbbr(target, cur);
            }
            return;
        }

        if (possible & (1 << step)) {
            dfs (step+1, cur|(1<<step));
        }
        dfs(step+1, cur);
    }
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        n = target.size();
        possible = 0;
        minLength = INT_MAX;
        this->target = target;
        int mask;
        for (auto &s : dictionary) {
            if (s.size() == n) {
                mask = getMask(target, s);
                possibleMasks.push_back(mask);
                // we only care different characters
                possible |= mask;
            }
        }
        dfs(0, 0);
        return res;
    }
};

int main() {
    return 0;
}
