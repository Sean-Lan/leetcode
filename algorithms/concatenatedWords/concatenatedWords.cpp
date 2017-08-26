/**
 *
 * Sean
 * 2017-08-26
 *
 * https://leetcode.com/problems/concatenated-words/description/
 *
 * Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
 *
 * A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
 *
 * Example:
 * Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 *
 * Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 *
 * Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 *  "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
 * "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
 * Note:
 * The number of elements of the given array will not exceed 10,000
 * The length sum of elements in the given array will not exceed 600,000.
 * All the input string will only include lower case letters.
 * The returned elements order does not matter.
 *
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// DP, but I think the complexity is O(n*l^2), which should be a TLE
// refer to Word Break problem: https://leetcode.com/problems/word-break/
class Solution {
    bool canForm(const string &word, unordered_set<string> &dict) {
        if (word.empty()) return false;
        int n = word.size();
        vector<bool> dp(n+1, false); // dp[i] = true means the first i characters (i.e, word.substr(0, i)) can be found in the dict
        dp[0] = true;
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                if (dp[j] && dict.count(word.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), [](const string &s, const string &t) {
           return s.size() < t.size();
        });

        unordered_set<string> dict;
        int n = words.size();
        for (int i=0; i<n; ++i) {
            if (canForm(words[i], dict)) {
                res.push_back(words[i]);
            }
            dict.insert(words[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}
