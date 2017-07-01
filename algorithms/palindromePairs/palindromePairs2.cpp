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
#include <string>
#include <vector>
using namespace std;

// Trie is very suitable to check whether a string has shown
struct TrieNode {
    int index;
    TrieNode *next[26];
    TrieNode(int index=-1) {
        this -> index = index;
        fill(next, next+26, nullptr);
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word, int index) {
        TrieNode *p = root;
        int n = word.size();
        int idx;
        for (int i=0; i<n; ++i) {
            idx = word[i] - 'a';
            if (!p->next[idx]) {
                p->next[idx] = new TrieNode();
            }
            p = p->next[idx];
        }
        p->index = index;
    }

    int search(const string &word) {
        TrieNode *p = root;
        int n = word.size();
        int idx;
        for (int i=0; i<n; ++i) {
            idx = word[i] - 'a';
            if (!p->next[idx]) return -1;
            p = p->next[idx];
        }
        return p->index;
    }
};

class Solution {
    bool isPalindrome(const string &s) {
        if (s.empty()) return true;
        int i=0, j = s.size()-1;

        while (i<j) {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if (words.empty()) return {};

        Trie trie = Trie();
        int n = words.size();
        vector<vector<int>> res;

        for (int i=0; i<n; ++i) {
            trie.insert(words[i], i);
        }

        int k;
        for (int i=0; i<n; ++i) {
            string &word = words[i];
            if (word.empty()) continue;
            for (int j=0; j<=word.size(); ++j) {
                string a = word.substr(0,j);
                string b = word.substr(j);
                if (isPalindrome(a)) {
                    string b_rev = string(b.rbegin(), b.rend());
                    k = trie.search(b_rev);
                    if (k != -1 && k != i) {
                        if (j != 0 || k > i)
                            res.push_back({k, i});
                    }
                }
                if (isPalindrome(b)) {
                    string a_rev = string(a.rbegin(), a.rend());
                    k = trie.search(a_rev);
                    if (k != -1 && k != i) {
                        if (j != word.size() || k > i)
                            res.push_back({i, k});
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
