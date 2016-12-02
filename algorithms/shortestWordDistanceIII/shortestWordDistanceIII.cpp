/**
 *
 * Sean
 * 2016-12-02
 *
 * https://leetcode.com/problems/shortest-word-distance-iii/
 *
 * This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
 *
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 *
 * word1 and word2 may be the same and they represent two individual words in the list.
 *
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Given word1 = “makes”, word2 = “coding”, return 1.
 * Given word1 = "makes", word2 = "makes", return 3.
 *
 * Note:
 * You may assume word1 and word2 are both in the list.
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        int shortestWordDistance(vector<string>& words, string word1, string word2) {
            int last1 = -1, last2 = -1;
            int d = INT_MAX;
            if (word1 == word2) {
                for (int i=0; i<words.size(); ++i) {
                    if (words[i] == word1) {
                        if (last1 != -1) {
                            d = min(d, i-last1);
                        }
                        last1 = i;
                    }
                }
            } else {
                for (int i=0; i<words.size(); ++i) {
                    if (words[i] == word1) {
                        if (last2 != -1) {
                            d = min(d, i-last2);
                        }
                        last1 = i;
                    } else if (words[i] == word2) {
                        if (last1 != -1) {
                            d = min(d, i-last1);
                        }
                        last2 = i;
                    }
                }
            }
            return d;
        }
};

int main() {
    return 0;
}
