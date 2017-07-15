/**
 *
 * Sean
 * 2017-07-15
 *
 * https://leetcode.com/problems/word-abbreviation/#/description
 *
 * Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.
 *
 * Begin with the first character and then the number of characters abbreviated, which followed by the last character.
 * If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
 * If the abbreviation doesn't make the word shorter, then keep it as original.
 *
 * Example:
 *
 * Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
 * Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
 *
 * Note:
 * Both n and the length of each word will not exceed 400.
 * The length of each word is greater than 1.
 * The words consist of lowercase English letters only.
 * The return answers should be in the same order as the original array.
 *
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// the key part is how to group simialr words together
//
// two creation will be considered:
// 1. the length of the word
// 2. the last character of the word
//
// if two words with different lengths, definitely their abbrevitaion will differ
// if two words have the same length but different trailing characters, their abbreviation will differ too
//
// First group the words by sorting them, then do a one pass check.
// The abbreviation of a word only relates to its previous word and next word.
class Solution {
    string getAbbr(const string &s, int beg) {
        if (s.size() - beg <= 3) return s;
        return s.substr(0, beg+1) + to_string(s.size()-beg-2) + s.back();
    }
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        if (dict.empty()) return {};

        int n = dict.size();
        vector<pair<string, int>> dict_index(n);
        for (int i=0; i<n; ++i) {
            dict_index[i] = {dict[i], i};
        }

        sort(dict_index.begin(), dict_index.end(), [](const pair<string, int> &p1, const pair<string, int> &p2) {
            if (p1.first.size() != p2.first.size()) return p1.first.size() < p2.first.size();
            if (p1.first.back() != p2.first.back()) return p1.first.back() < p2.first.back();
            return p1.first < p2.first;
        });

        vector<string> res(n);
        int lastDiffPos = 0;

        for (int i=0; i<n; ++i) {
            auto &cur = dict_index[i].first;
            auto &cur_index = dict_index[i].second;
            if (i == n-1) {
                res[cur_index] = getAbbr(cur, lastDiffPos);
                continue;
            }
            auto &next = dict_index[i+1].first;
            if (cur.size() != next.size()) { // enter a new group with different lengths
                res[cur_index] = getAbbr(cur, lastDiffPos);
                lastDiffPos = 0;
            } else {
                if (cur.back() != next.back()) { // enter a new group with different trailing characters
                    res[cur_index] = getAbbr(cur, lastDiffPos);
                    lastDiffPos = 0;
                } else { // with the same lengh and same trailing character
                    int j = 0;
                    while (j < cur.size() && cur[j] == next[j]) ++j;
                    res[cur_index] = getAbbr(cur, max(lastDiffPos, j));
                    lastDiffPos = j;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<string> dict = {
        "like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"
    };
    auto res = solution.wordsAbbreviation(dict);
    for (auto &w : res) {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}
