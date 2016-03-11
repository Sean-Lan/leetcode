/**
 *
 * Sean
 * 2016-03-11
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
        bool inline invalid(char &c) {
            return c<'0' || c>'9';
        }

    public:
        int numDecodings(string s) {
            if (s.empty())
                return 0;
            vector<int> dp(s.size()+1, 0);
            dp[0]=1;
            if (invalid(s[0])) return 0;
            dp[1] = (s[0]!='0')?1:0;
            short tmp;
            char c1, c2;
            for (int i=2; i<dp.size(); i++) {
                c1 = s[i-1], c2 = s[i-2];
                if (invalid(c1)) return 0;
                if (c1!='0')
                    dp[i] = dp[i-1];
                tmp = 10*(c2-'0') + c1-'0';
                if (tmp <= 26 && tmp>= 10)
                    dp[i] += dp[i-2];
            }
            return dp[s.size()];
        }
};

int main() {
    Solution s;
    cout << s.numDecodings("10") << endl;
}
