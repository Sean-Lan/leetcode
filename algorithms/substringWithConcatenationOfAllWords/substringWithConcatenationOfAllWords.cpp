/**
 *
 * Sean
 * 2016-02-22
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 *
 * You are given a string, s, and a list of words, words, that are all of the same length.
 * Find all starting indices of substring(s) in s that is a concatenation of each word
 * in words exactly once and without any intervening characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 *
 */
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/**
 *
 * Use a slide window to mark down all the words that in vector words.
 * Slide the window in the following cases:
 * 1. the current word isn't in vector words;
 * 2. the occurence count of current word is larger than that in vector words.
 *
 * Be careful with string.size(), it result a unsigned long int, and make sure use something like
 * (j+wordLength <= s.size()), instead of (j <= s.size()-wordLength).
 *
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty())
            return result;
        unordered_map<string, int> wordDict;
        for (auto &word : words)
            ++wordDict[word];
        int wordLength = words[0].size();
        int left;
        unordered_map<string, int> currentDict;
        string word;
        int cnt;
        for (int i=0; i<wordLength; ++i) {
            left = i;
            cnt = 0;
            currentDict.clear();
            for (int j=i; j+wordLength<=s.size(); j+=wordLength) {
                word = s.substr(j, wordLength);
                if (wordDict.find(word) != wordDict.end()) {
                    ++currentDict[word];
                    ++cnt;
                    while (currentDict[word] > wordDict[word]) {
                        --currentDict[s.substr(left, wordLength)];
                        left += wordLength;
                        --cnt;
                    }
                    if (cnt == words.size()) {
                        result.push_back(left);
                        --currentDict[s.substr(left, wordLength)];
                        left += wordLength;
                        --cnt;
                    }
                } else {
                    left = j+wordLength;
                    currentDict.clear();
                    cnt = 0;
                }
            }
        }
        return result;
    }
};

void printResult(const vector<int> &result) {
    for (auto &i : result) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"foo", "bar", "the"};
    Solution solution;
    printResult(solution.findSubstring(s, words));
    return 0;
}
