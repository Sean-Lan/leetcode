/**
 *
 * Sean
 * 2016-06-28
 *
 * https://leetcode.com/problems/word-ladder/
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the word list
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 *
 */
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

// BFS
class Solution {
typedef pair<string, int> si;
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<si> aQueue;
        aQueue.push({beginWord, 1});
        wordList.insert(endWord);
        while (!aQueue.empty()) {
            si aPair = aQueue.front();
            aQueue.pop();
            for (int i=0; i<aPair.first.size(); ++i) {
                for (char j='a'; j<='z'; ++j) {
                    string word = aPair.first;
                    word[i] = j;
                    auto it = wordList.find(word);
                    if (it!=wordList.end()) {
                        if (word == endWord)
                            return aPair.second+1;
                        wordList.erase(it);
                        aQueue.push({word, aPair.second+1});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {}
