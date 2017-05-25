/**
 *
 * Sean
 * 2017-05-25
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/#/description
 *
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 *
 * For example:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 *
 */
#include <iostream>
#include <string>
using namespace std;

// use Trie
// O(L) insertion
// O(26^numberOf('.')*L) search
struct TrieNode {
    bool isWord;
    TrieNode *next[26];
    TrieNode(bool isWord = false) {
        this->isWord = isWord;
        fill(next, next+26, nullptr);
    }
};

class WordDictionary {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        int idx;
        TrieNode *p = root;
        for (int i=0; i<n; ++i) {
            idx = word[i] - 'a';
            if (!p->next[idx]) p->next[idx] = new TrieNode();
            p = p->next[idx];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(root, word, 0);
    }

private:
    TrieNode *find(TrieNode *p, const string& word, int idx) {
        if (idx == word.size()) return p;
        char c = word[idx];
        TrieNode *res = nullptr;
        if (c == '.') {
            for (int i=0; i<26; ++i) {
                if (!p->next[i]) continue;
                res = find(p->next[i], word, idx+1);
                if (res && res->isWord) return res;
            }
        } else {
            if (p->next[c-'a'])
                res = find(p->next[c-'a'], word, idx+1);
        }
        if (res && res->isWord) return res;
        return nullptr;
    }
};

int main() {
    WordDictionary dict = WordDictionary();
    dict.addWord("a");
    cout << dict.search("a") << endl;
    cout << dict.search("b") << endl;
    return 0;
}
