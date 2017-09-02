/**
 *
 * Sean
 * 2017-09-02
 *
 * https://leetcode.com/problems/word-squares/description/
 *
 * Given a set of words (without duplicates), find all word squares you can build from them.
 *
 * A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
 *
 * For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
 *
 * b a l l
 * a r e a
 * l e a d
 * l a d y
 * Note:
 * There are at least 1 and at most 1000 words.
 * All words will have the exact same length.
 * Word length is at least 1 and at most 5.
 * Each word contains only lowercase English alphabet a-z.
 * Example 1:
 *
 * Input:
 * ["area","lead","wall","lady","ball"]
 *
 * Output:
 * [
 *   [ "wall",
 *     "area",
 *     "lead",
 *     "lady"
 *   ],
 *   [ "ball",
 *     "area",
 *     "lead",
 *     "lady"
 *   ]
 * ]
 *
 * Explanation:
 * The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
 * Example 2:
 *
 * Input:
 * ["abat","baba","atan","atal"]
 *
 * Output:
 * [
 *   [ "baba",
 *     "abat",
 *     "baba",
 *     "atan"
 *   ],
 *   [ "baba",
 *     "abat",
 *     "baba",
 *     "atal"
 *   ]
 * ]
 *
 * Explanation:
 * The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
 *
 */
#include <string>
#include <vector>
using namespace std;

// Trie
// each TrieNode needs to store all the words with the prefix of current node
struct TrieNode {
    vector<string> words;
    TrieNode *next[26];
    TrieNode() { fill(next,next+26, nullptr); }
};

class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }
    void insert(string &word) {
        TrieNode *p = root;
        for (int i=0; i<word.size(); ++i) {
            p->words.push_back(word);
            if (!p->next[word[i]-'a']) p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->words.push_back(word);
    }
    TrieNode *find(string &word) {
        TrieNode *p = root;
        for (int i=0; i<word.size(); ++i) {
            if (!p) break;
            p = p->next[word[i]-'a'];
        }
        return p;
    }
};

class Solution {
    int len, n;
    vector<vector<string>> res;
    vector<string> path;
    Trie trie;

    void sovle(vector<string> &words) {
        if (path.size() == len) {
            res.push_back(path);
            return;
        }
        int curLen = path.size();
        string prefix;
        for (int i=0; i<curLen; ++i) prefix += path[i][curLen];
        TrieNode *p = trie.find(prefix);
        if (!p) return;
        for (auto &word : p->words) {
            path.push_back(word);
            sovle(words);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return {};
        n = words.size();
        len = words[0].size();

        for (auto &word : words) trie.insert(word);

        sovle(words);
        return res;
    }
};

int main() {
    return 0;
}
