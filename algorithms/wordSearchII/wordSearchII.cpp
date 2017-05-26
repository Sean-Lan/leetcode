/**
 *
 * Sean
 * 2017-05-26
 *
 * https://leetcode.com/problems/word-search-ii/#/description
 *
 * Given a 2D board and a list of words from the dictionary, find all words in the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 *
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board =
 *
 * [
 *  ['o','a','a','n'],
 *  ['e','t','a','e'],
 *  ['i','h','k','r'],
 *  ['i','f','l','v']
 * ]
 *
 * Return ["eat","oath"].
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// use trie to do the pruing work
struct TrieNode {
    bool isWord;
    TrieNode *next[26];
    TrieNode(bool isWord=false) {
        this->isWord = isWord;
        fill (next, next+26, nullptr);
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(const string& word) {
        int idx;
        int n = word.size();
        TrieNode *p = root;
        for (int i = 0; i<n; ++i) {
            idx = word[i] - 'a';
            if (!p->next[idx]) {
                p->next[idx] = new TrieNode();
            }
            p = p->next[idx];
        }
        p -> isWord = true;
    }

    TrieNode *find(const string &word) {
        TrieNode *p = root;
        int n = word.size();
        for (int i=0; i<n &&p; ++i)
            p = p->next[word[i] - 'a'];
        return p;
    }
};

static const int directions[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
class Solution {
    int m, n;
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &mark, string &cur, int curX, int curY, Trie &trie, unordered_set<string> &res) {
        if (mark[curX][curY]) return;
        int nextX, nextY;
        cur.push_back(board[curX][curY]);
        TrieNode *p = trie.find(cur);
        if (!p) {
            cur.pop_back();
            return;
        }

        if (p->isWord) {
            res.insert(cur);
        }
        mark[curX][curY] = true;
        for (auto d : directions) {
            nextX = curX + d[0];
            nextY = curY + d[1];
            if (isValid(nextX, nextY))
                dfs(board, mark, cur, nextX, nextY, trie, res);
        }
        mark[curX][curY] = false;
        cur.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if (m == 0) return {};
        int n = board[0].size();
        if (n == 0) return {};
        this->m = m;
        this->n = n;
        Trie trie;
        for (auto &w : words) {
            trie.insert(w);
        }
        vector<vector<bool>> mark(m, vector<bool>(n, false));
        string cur;
        unordered_set<string> res;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                dfs(board, mark, cur, i, j, trie, res);
            }
        return vector<string>(res.begin(), res.end());
    }
};

int main() {
    vector<string> lines = {
        "bbaaba","bbabaa","bbbbbb","aaabaa","abaabb"
    };
    vector<vector<char>> board;
    for (auto &s : lines) {
        vector<char> cV;
        for (auto c : s) {
            cV.push_back(c);
        }
        board.push_back(cV);
    }
    vector<string> words = {"abbbababaa"};

    Solution solution;
    vector<string> res =  solution.findWords(board, words);
    for (auto &w : res) {
        cout << w << endl;
    }
    return 0;
}
