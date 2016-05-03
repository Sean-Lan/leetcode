/**
 *
 * Sean
 * 2016-05-03
 *
 * https://leetcode.com/problems/edit-distance/
 *
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Typical dp.
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size(), n = word2.size();
            vector<vector<int>> dp(m+1, vector<int>(n+1));
            for (int i=0; i<=m; ++i)
                dp[i][0] = i;
            for (int j=0; j<=n; ++j)
                dp[0][j] = j;
            for (int i=1; i<=m; ++i)
                for (int j=1; j<=n; ++j) {
                    int tmp = std::numeric_limits<int>::max();
                    if (word1[i-1] == word2[j-1])
                        tmp = dp[i-1][j-1];
                    tmp = min(tmp, dp[i-1][j-1]+1); // replace
                    tmp = min(tmp, dp[i-1][j]+1);   // insert into word1
                    tmp = min(tmp, dp[i][j-1]+1);   // insert into word2
                    dp[i][j] = tmp;
                }
            return dp[m][n];
        }
};

int main() {
    Solution solution;
    string word1 = "Sean", word2 = "sea";
    cout << solution.minDistance(word1, word2) << endl;
}
