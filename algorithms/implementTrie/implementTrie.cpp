/**
 *
 * Sean
 * 2017-05-25
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/#/description
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 */
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct TrieNode {
    bool isWord; // mark for whether there is a word ends at the node
    TrieNode *next[26];
    TrieNode(bool isWord = false) {
        this->isWord = isWord;
        fill(next, next+26, nullptr);
    }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix);
    }
private:
    TrieNode *find(const string &word) {
        int n = word.size();
        TrieNode *p = root;
        for (int i=0; i<n && p; ++i) {
            p = p->next[word[i]-'a'];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    return 0;
}
