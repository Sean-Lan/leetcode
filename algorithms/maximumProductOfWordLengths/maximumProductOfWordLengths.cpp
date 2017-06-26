/**
 *
 * Sean
 * 2017-06-26
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/#/description
 *
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
 *
 * Example 1:
 * Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * Return 16
 * The two words can be "abcw", "xtfn".
 *
 * Example 2:
 * Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * Return 4
 * The two words can be "ab", "cd".
 *
 * Example 3:
 * Given ["a", "aa", "aaa", "aaaa"]
 * Return 0
 * No such pair of words.
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// bit manipulation
// since all the characters of the word are in lower case, we can use an integer to represent the word to help the overlap check
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n < 2) return 0;
        vector<int> masks(n, 0);

        for (int i=0; i<n; ++i) {
            auto &w = words[i];
            auto &mask = masks[i];
            for (auto &c : w) {
                mask |= 1 << (c-'a');
            }
        }

        int maximum = 0;
        for (int i=0; i+1<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                auto &m1 = masks[i];
                auto &m2 = masks[j];
                if ((m1 & m2) == 0)
                    maximum = max(maximum, (int)(words[i].size()*words[j].size()));
            }
        }

        return maximum;
    }
};

int main() {
    return 0;
}
