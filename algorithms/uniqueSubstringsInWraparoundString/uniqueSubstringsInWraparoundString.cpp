/**
 *
 * Sean
 * 2017-07-27
 *
 * https://leetcode.com/problems/unique-substrings-in-wraparound-string/tabs/description
 *
 * Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 *
 * Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.
 *
 * Note: p consists of only lowercase English letters and the size of p might be over 10000.
 *
 * Example 1:
 * Input: "a"
 * Output: 1
 * Explanation: Only the substring "a" of string "a" is in the string s.
 *
 * Example 2:
 * Input: "cac"
 * Output: 2
 * Explanation: There are two substrings "a", "c" of string "cac" in the string s.
 *
 * Example 3:
 * Input: "zab"
 * Output: 6
 * Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
 *
 */
#include <string>
#include <vector>
using namespace std;

// DP
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // dp[i] means the maximum length of increasing sequence starting with 'a'+i
        vector<int> dp(26,0);
        int n = p.size();
        bool found = false;
        int cnt = 0;
        char c;
        int res = 0;
        for (int i=0; i<26; i++) {
            for (int j=0; j<n; ++j) {
                c = p[j];
                if (found) {
                    if ((p[j-1]-'a'+1)%26 == p[j]-'a') {
                        ++cnt;
                    } else if (c == 'a'+i) {
                        found = true;
                        cnt = 1;
                    } else {
                        cnt = 0;
                        found = false;
                    }
                } else if (c == 'a'+i) {
                    found = true;
                    cnt = 1;
                } else {
                    cnt = 0;
                    found = false;
                }
                dp[i] = max(dp[i], cnt);
            }
            cnt = 0;
            found = false;
            res += dp[i];
        }
        return res;
    }
};

int main() {
return 0;
}
