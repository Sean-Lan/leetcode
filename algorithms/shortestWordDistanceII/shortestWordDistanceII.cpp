/**
 *
 * Sean
 * 2017-06-06
 *
 * https://leetcode.com/problems/shortest-word-distance-ii/#/description
 *
 * This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
 *
 * Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
 *
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Given word1 = “coding”, word2 = “practice”, return 3.
 * Given word1 = "makes", word2 = "coding", return 1.
 *
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 *
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class WordDistance {
    // table[w] stores the shown index of word w
    unordered_map<string, vector<int>> table;
public:
    // O(n*log(n))
    WordDistance(vector<string> words) {
        int n = words.size();
        for (int i=0; i<n; ++i) {
            table[words[i]].push_back(i);
        }
    }

    // O(n)
    int shortest(string word1, string word2) {
        auto &v1 = table[word1];
        auto &v2 = table[word2];

        int d = INT_MAX;
        int m = v1.size();
        int n = v2.size();
        int i=0, j=0;
        int idx1, idx2;
        while (i<m && j<n) {
            idx1 = v1[i];
            idx2 = v2[j];
            if (idx1 < idx2) {
                d = min(d, idx2-idx1);
                ++ i;
            } else {
                d = min(d, idx1-idx2);
                ++ j;
            }
        }
        return d;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

int main() {
    return 0;
}
