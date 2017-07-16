/**
 *
 * Sean
 * 2017-07-16
 *
 * https://leetcode.com/problems/sentence-screen-fitting/#/description
 *
 * Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.
 *
 * Note:
 *
 * A word cannot be split into two lines.
 * The order of words in the sentence must remain unchanged.
 * Two consecutive words in a line must be separated by a single space.
 * Total words in the sentence won't exceed 100.
 * Length of each word is greater than 0 and won't exceed 10.
 * 1 ≤ rows, cols ≤ 20,000.
 * Example 1:
 *
 * Input:
 * rows = 2, cols = 8, sentence = ["hello", "world"]
 *
 * Output:
 * 1
 *
 * Explanation:
 * hello---
 * world---
 *
 * The character '-' signifies an empty space on the screen.
 * Example 2:
 *
 * Input:
 * rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
 *
 * Output:
 * 2
 *
 * Explanation:
 * a-bcd-
 * e-a---
 * bcd-e-
 *
 * The character '-' signifies an empty space on the screen.
 * Example 3:
 *
 * Input:
 * rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
 *
 * Output:
 * 1
 *
 * Explanation:
 * I-had
 * apple
 * pie-I
 * had--
 *
 * The character '-' signifies an empty space on the screen.
 *
 */
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

// DP
// O(max(n*n), rows))
// dp[i] means starting from the i-th (i starts from 0) word, how many words can be
// put into the row
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int num = 0;
        int n = sentence.size();
        vector<int> dp(n, -1);
        vector<int> lengths;
        int maxLen = 0;
        int sz;
        int sum = 0;
        for (auto &word : sentence) {
            sz = word.size();
            lengths.push_back(sz);
            if (sz > maxLen) maxLen = sz;
            sum += sz + 1;
        }
        if (maxLen > cols) return 0;

        for (int i=0; i<rows; ++i) {
            int start = num % n;
            if (dp[start] > 0) {
                num += dp[start];
            } else {
                int cnt = cols / sum * n;
                int remain = cols % sum;
                if (remain != 0) {
                    int len = 0;
                    int j = start;
                    while (len + lengths[j] <= remain) {
                        len += lengths[j] + 1;
                        ++ cnt;
                        j = (j+1) % n;
                    }
                }
                num += cnt;
                dp[start] = cnt;
            }
        }
        return num / n;
    }
};

int main() {
    return 0;
}
