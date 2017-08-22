/**
 *
 * Sean
 * 2017-08-21
 *
 * https://leetcode.com/problems/encode-string-with-shortest-length/description/
 *
 * Given a non-empty string, encode the string such that its encoded length is the shortest.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
 *
 * Note:
 * k will be a positive integer and encoded string will not be empty or have extra space.
 * You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
 * If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.
 *
 * Example 1:
 * Input: "aaa"
 * Output: "aaa"
 * Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
 *
 * Example 2:
 * Input: "aaaaa"
 * Output: "5[a]"
 * Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
 *
 * Example 3:
 * Input: "aaaaaaaaaa"
 * Output: "10[a]"
 * Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
 *
 * Example 4:
 * Input: "aabcaabcd"
 * Output: "2[aabc]d"
 * Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
 *
 * Example 5:
 * Input: "abbbabbbcabbbabbbc"
 * Output: "2[2[abbb]c]"
 * Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O(n^4) :: maybe not very tight
// dp[i][j] means the shortest encoded string s[i..j]
// dp[i][j] can be obtained from two ways:
//   1. split it into two halves, encoded the two halves separately
//   2. get a substr of it, repeat the substr to check whether it can form the original one, (here, we need to use encoded form of the substr to get the best benefit from encoding
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n));

        for (int l=1; l<=n; ++l) {
            for (int i=0; i+l<=n; ++i) {
                string origin = s.substr(i, l);
                dp[i][i+l-1] = origin;
                if (l > 4) {
                    for (int j=1; j<l; ++j) {
                        string tmp = dp[i][i+j-1] + dp[i+j][i+l-1];
                        if (tmp.size() < dp[i][i+l-1].size()) dp[i][i+l-1] = tmp;
                    }

                    for (int j=1; j<l; ++j) {
                        if (l%j != 0) continue;
                        int m = l/j;
                        string p = s.substr(i, j);
                        string tmp;
                        for (int k=0; k<m; ++k) tmp += p;

                        if (tmp == origin) {
                            string res = to_string(m) + '[' + dp[i][i+j-1] + ']';
                            if (res.size() < dp[i][i+l-1].size())
                                dp[i][i+l-1] = res;
                        }
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};

int main() {
    return 0;
}
