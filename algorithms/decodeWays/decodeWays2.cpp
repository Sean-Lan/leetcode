/**
 *
 * Sean
 * 2016-05-02
 *
 * https://leetcode.com/problems/decode-ways/
 *
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// dp
class Solution {
    private:
        bool isValid(char c) {
            return (c>='1' && c<='9');
        }

        bool isValid(char c1, char c2) {
            return (c1 == '1' && c2>='0' && c2<='9') ||
                   (c1 == '2' && c2>='0' && c2<='6');
        }

    public:
        int numDecodings(string s) {
            if (s.empty()) return 0;
            vector<int> dp(s.size()+1, 0);
            dp[0] = 1;
            dp[1] = isValid(s[0]);
            int n = s.size();
            for (int i=1; i<n; ++i) {
                if (isValid(s[i]))
                    dp[i+1] += dp[i];
                if (isValid(s[i-1], s[i]))
                    dp[i+1] += dp[i-1];
            }
            return dp[n];
        }
};

int main() {
    Solution s;
    cout << s.numDecodings("27") << endl;
}
