/**
 *
 * Sean
 * 2017-05-28
 *
 * https://leetcode.com/problems/shortest-palindrome/#/description
 *
 * Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
 *
 * For example:
 *
 * Given "aacecaaa", return "aaacecaaa".
 *
 * Given "abcd", return "dcbabcd".
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<int> prefixTable(const string& s) {
        if (s.empty()) return {};
        int n = s.size();
        vector<int> table(n, 0);
        table[0] = 0;
        int i = 0, pos = 1;
        while (pos < n) {
            if (s[pos] == s[i]) {
                table[pos] = i + 1;
                ++ i;
                ++ pos;
            } else if (i > 0){
                i = table[i-1];
            } else {
                table[pos] = 0;
                ++ pos;
            }
        }
        return table;
    }

public:
    // if s is palindromic, then it eqauls to its reverse
    // the repeated is like the following:
    // <s>#<reversed_s>
    // <`palindromic-part``inpalindromic-part`>#<`reversed inpalindromic-part``palindromic-part`>
    // so we only need to construct the prefix table to repeated string, then we can build the result string like:
    // `reversed inpalindromic-part` + `palindromic-part` + `inpalindromic-part`
    string shortestPalindrome(string s) {
        if (s.empty()) return "";
        string repeated(s.rbegin(), s.rend());
        repeated = s + '#' + repeated;
        auto table = prefixTable(repeated);
        int palindromeLength = table[repeated.size()-1];
        string res = s.substr(palindromeLength);
        reverse(res.begin(), res.end());
        res += s;
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.shortestPalindrome("a") << endl;
    return 0;
}
