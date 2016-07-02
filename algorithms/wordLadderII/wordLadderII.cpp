/**
 *
 * Sean
 * 2016-07-02
 *
 * https://leetcode.com/problems/word-ladder-ii/
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the word list
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * Return
 *   [
 *       ["hit","hot","dot","dog","cog"],
 *       ["hit","hot","lot","log","cog"]
 *   ]
 * Note:
 *  All words have the same length.
 *  All words contain only lowercase alphabetic characters.
 *
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void printPrevious(unordered_map<string, unordered_set<string>> &previous);

typedef vector<vector<string>> vvs;

// Using BFS to contruct the predecessor subgraph, and using DFS with backtracking to contruct the final result.
class Solution {
    typedef pair<string, int> si;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        if (beginWord == endWord) {
            vector<vector<string>> results = {{beginWord}};
            return results;
        }
        queue<si> aQueue;
        unordered_map<string, unordered_set<string>> previous;
        unordered_map<string, int> levelCnt; // the length of shortest ladder to a certain word
        levelCnt[beginWord] = 1;
        aQueue.push({beginWord, 1});
        bool found = false;
        int shortestLen = 0;
        while (!aQueue.empty()) {
            auto aPair = aQueue.front();
            aQueue.pop();

            // the problem is to find the shortest ladder, skip the word too different from beginWord.
            if (found && aPair.second == shortestLen) continue;

            string &curWord = aPair.first;
            string origin = aPair.first;
            // try each possible next word.
            for (int i=0; i<curWord.size(); ++i) {
                // flag to break this for loop
                bool shouldBreak = false;
                char curLetter = curWord[i];
                for (char j='a'; j<='z'; ++j) {
                    if (curWord[i]!=j) {
                        curWord[i] = j;
                        if (curWord == endWord) {
                            previous[curWord].insert(origin);
                            found = true;
                            shouldBreak = true;
                            shortestLen = aPair.second+1;
                            break;
                        }
                        if (wordList.count(curWord)) {
                            if (levelCnt.count(curWord)) {
                                if (levelCnt[curWord] == aPair.second+1) { // another shortest ladder to curWord
                                    previous[curWord].insert(origin);
                                }
                            } else { // the first time to visit curWord
                                levelCnt[curWord] = aPair.second + 1;
                                previous[curWord].insert(origin);
                                aQueue.push({curWord, aPair.second+1});
                            }
                        }
                        curWord[i] = curLetter;
                    }
                }
                if (shouldBreak) break;
            }
        }
        vector<vector<string>> results;
        constructResult(results, previous, beginWord, endWord);
        return results;
    }

private:
    void constructResult(vector<vector<string>> &results, unordered_map<string, unordered_set<string>> &previous,
                         string &beginWord, string &endWord) {
//        printPrevious(previous);
        vector<string> result;
        constructHelper(results, result, previous, endWord, beginWord);
    }

    void constructHelper(vector<vector<string>> &results, vector<string> &result, unordered_map<string,
            unordered_set<string>> &previous, const string &curWord, const string &beginWord) {
        result.push_back(curWord);
        if (curWord == beginWord) {
            vector<string> reversed(result.rbegin(), result.rend());
            results.push_back(reversed);
        } else {
            for (auto &nextWord : previous[curWord]) {
                constructHelper(results, result, previous, nextWord, beginWord);
            }
        }
        result.pop_back();
    }

};

void printPrevious(unordered_map<string, unordered_set<string>> &previous) {
    for (auto &aPair : previous) {
        cout << aPair.first << ": " << endl;
        cout << "\t";
        for (auto &s : aPair.second)
            cout << s << " ";
        cout << endl;
    }
}

void printResult(vvs &results) {
    for (auto &vs : results) {
        for (auto &s : vs)
            cout << s << " ";
        cout << endl;
    }
}

int main() {
    Solution solution;

    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = { "hot", "dot", "dog", "lot", "log" };

    auto results = solution.findLadders(beginWord, endWord, wordList);
    printResult(results);
}
