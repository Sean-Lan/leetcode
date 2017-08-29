/**
 *
 * Sean
 * 2017-08-29
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * Given a 2D board and a list of words from the dictionary, find all words in the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 *
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board =
 *
 * [
 *   ['o','a','a','n'],
 *   ['e','t','a','e'],
 *   ['i','h','k','r'],
 *   ['i','f','l','v']
 * ]
 * Return ["eat","oath"].
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// passing along the TrieNode to help check whether a prefix exist in O(1)
// remember to mark a word found by set isWord as false
static const int D[4][2] = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

struct TrieNode {
    TrieNode *next[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        fill(next, next+26, nullptr);
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode *p = root;
        int n = word.size(), idx;
        for (int i=0; i<n; ++i) {
            idx = word[i]-'a';
            if (!p->next[idx]) p->next[idx] = new TrieNode();
            p = p->next[idx];
        }
        p->isWord = true;
    }

    TrieNode *find(string &word) {
        TrieNode *p = root;
        int n = word.size(), idx;
        for (int i=0; i<n; ++i) {
            idx = word[i]-'a';
            p = p->next[idx];
            if (!p) break;
        }
        return p;
    }
};

class Solution {
    int m, n;
    inline bool isValid(int i, int j) {
        return i>=0 && i<m && j>=0 && j<n;
    }
    void sovle(int i, int j, vector<vector<char>> &board, string &path, TrieNode *p, vector<string> &res) {
        path.push_back(board[i][j]);
        p = p->next[board[i][j]-'a'];

        if (p) {
            board[i][j] = ' ';
            if (p->isWord) {
                res.push_back(path);
                p->isWord = false; // dedup
            }
            int ii, jj;
            for (auto d : D) {
                ii = i + d[0];
                jj = j + d[1];
                if (isValid(ii, jj) && board[ii][jj] != ' ') {
                   sovle(ii, jj, board, path, p, res);
                }
            }
            board[i][j] = path.back();
        }

        path.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return {};
        m = board.size();
        n = board[0].size();
        vector<string> res;
        string path;
        Trie trie;
        for(auto &word : words) trie.insert(word);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                sovle(i, j, board, path, trie.root, res);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
