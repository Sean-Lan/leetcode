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
#include <string>
#include <algorithm>
using namespace std;

// use trie to do the pruning work
struct TrieNode {
    bool isWord;
    TrieNode *next[26];
    TrieNode(bool isWord=false) {
        this->isWord = isWord;
        fill(next, next+26, nullptr);
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

    void dfs(vector<vector<char>> &board, string &cur, int curX, int curY, TrieNode *p, vector<string> &res) {
        char c = board[curX][curY];
        if (c == '#') return;
        cur.push_back(c);
        int nextX, nextY;
        TrieNode *next = p->next[c-'a'];
        if (!next) {
            cur.pop_back();
            return;
        }

        if (next->isWord) {
            res.push_back(cur);
            next->isWord = false; // de-duplicate
        }

        // mark for visited
        board[curX][curY] = '#';
        for (auto d : directions) {
            nextX = curX + d[0];
            nextY = curY + d[1];
            if (isValid(nextX, nextY))
                dfs(board, cur, nextX, nextY, next, res);
        }
        // restore
        board[curX][curY] = c;
        cur.pop_back();
    }

    void buildTrie(TrieNode *p, const string& word) {
        int idx;
        int n = word.size();
        for (int i = 0; i<n; ++i) {
            idx = word[i] - 'a';
            if (!p->next[idx])
                p->next[idx] = new TrieNode();
            p = p->next[idx];
        }
        p -> isWord = true;
    }

    void deleteTrie(TrieNode *p) {
        if (!p) return;
        for (auto pNext : p->next)
            if (pNext) deleteTrie(pNext);
        delete p;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if (m == 0) return {};
        int n = board[0].size();
        if (n == 0) return {};
        this->m = m;
        this->n = n;

        TrieNode *root = new TrieNode();
        for (auto &w : words)
            buildTrie(root, w);

        string cur;
        vector<string> res;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                dfs(board, cur, i, j, root, res);

        // good habit to free the memory
        deleteTrie(root);
        return res;
    }
};

int main() {
    return 0;
}
