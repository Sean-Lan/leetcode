/**
 *
 * Sean
 * 2017-07-01
 *
 * https://leetcode.com/problems/palindrome-pairs/#/description
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
 *
 * Example 1:
 * Given words = ["bat", "tab", "cat"]
 * Return [[0, 1], [1, 0]]
 * The palindromes are ["battab", "tabbat"]
 *
 * Example 2:
 * Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 * Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 * The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 *
 */
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// O(n*(l^2)), n is the size of words and l is the maximum length of a word in words
// use a hash table to store the map from word to its index
// for each word, check whether its prefix or suffix exists in the table
// three edge cases needs to consider:
// 1. empty string
// 2. the word itself is a palindrome
// 3. the word and its reverse are both in the array (need to dedup, consider the pairs once at its first time, i.e., i < k)
class Solution {
    bool isPalindrome(const string &s) {
        if (s.empty()) return true;
        int i=0;
        int j = s.size()-1;

        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if (words.empty()) return {};
        unordered_map<string, int> table;
        int n = words.size();

        for (int i=0; i<n; ++i) {
            table[words[i]] = i;
        }

        vector<vector<int>> res;
        int k;
        for (int i=0; i<n; ++i) {
            auto &word = words[i];
            if (word.empty()) continue;
            for (int j=0; j<=word.size(); ++j) {
                string a = word.substr(0, j);
                string b = word.substr(j);
                if (isPalindrome(a)) {
                    string b_rev = string(b.rbegin(), b.rend());
                    if (table.count(b_rev) && (k=table[b_rev]) != i) {
                        if (j != 0 || k > i) { // dedup
                            res.push_back({k, i});
                        }
                    }
                }
                if (isPalindrome(b)) {
                    string a_rev = string(a.rbegin(), a.rend());
                    if (table.count(a_rev) && (k=table[a_rev]) != i) {
                        if (j != word.size() || k > i) { // dedup
                            res.push_back({i, k});
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
