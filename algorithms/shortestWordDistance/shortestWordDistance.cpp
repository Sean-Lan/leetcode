/**
 *
 * Sean
 * 2016-11-29
 *
 * https://leetcode.com/problems/shortest-word-distance/
 *
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
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
#include <vector>
using namespace std;

// O(n)
// last1, last2 point to the last showing index of word1 and word respectively.
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int d = INT_MAX;
        int last1 = -1, last2 = -1;
        for (int i=0; i<words.size(); ++i) {
            if (words[i] == word1) {
                last1 = i;
                if (last2 != -1) {
                    d = min(d, last1-last2);
                }
                continue;
            }
            if (words[i] == word2) {
                last2 = i;
                if (last1 != -1) {
                    d = min(d, last2-last1);
                }
                continue;
            }
        }
        return d;
    }
};

int main() {
    return 0;
}
