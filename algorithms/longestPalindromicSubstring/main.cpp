/**
 *
 * Sean
 * 2015-04-26
 *
 * https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Given a string S, find the longest palindromic substring in S. You may assume
 * that the maximum length of S is 1000, and there exists one unique longest 
 * palindromic substring.
 *
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        static const int MAX_LENTH = 1000;

        /**
         *
         * O(n^2) method using dp.
         * Boolean array dp is used to mark the palindromic substr.
         * s[i:j] is palindromic, iff dp[i][j] is true.
         * dp[x][y] = (s[x]==s[y] && dp[x+1][y-1])
         *
         */
        string longestPalindrome(string s) {
            // dp initialization 
            for (st i = 0; i!=s.size(); ++i)
                dp[i][i] = true; 

            st beg=0, end=0; 
            /**
             *
             * tranverse the dp array diagonally:
             *  0 1 2 3 4 5 6   y
             * 0+--------------->
             * 1| 1 0         |
             * 2|   1 0       |
             * 3|     1 ...   |
             * 4|       1     |
             * 5|         1   |
             * 6|             |
             * x|            length(s)
             * 
             * y = x+b (1<=b<length(s),0<=x<length(s))
             * y < length(s) 
             * Enumerate b from 1 to length(s)-1, we can get diagonal
             * lines sequencelly, and enumerate x from 0 to the maximum
             * value so that y equals length(s)-1.
             *
             */
            for (st i = 1; i != s.size(); ++i) {
               for (st x = 0; x+i != s.size(); ++x) {
                   calculatePalinromic(s, x, x+i, beg, end);
               } 
            }
            return s.substr(beg, end-beg+1);
        }

        /* naive O(n^3) method, and have a TLE */
        string longestPalindrome_naive(string s) {
            string longestSubStr = s.substr(0,1);
            string tmpSubStr;
            for (st i = 0; i != s.size(); ++i) {
                for (st j = i+1; j != s.size(); ++j) {
                    tmpSubStr = s.substr(i,j-i+1);
                    if (isPalindromic(tmpSubStr) && 
                            (longestSubStr.size() < tmpSubStr.size()) )
                        longestSubStr = tmpSubStr;
                }
            }
            return longestSubStr;
        }
    private:
        static bool dp[MAX_LENTH][MAX_LENTH];
        typedef string::size_type st;

        /**
         *
         * check whether s[x:y] is palindromic; if so, check whether the new
         * substr is longer than the recorded substr.
         * return the begin and end position of the palindromic substr.
         *
         */
        void calculatePalinromic(string& s, st x, st y, st& beg, st& end) {
            /* specila case. Because we assume x<y, if x+1==y, x+1>y-1. */
            if (x+1 == y)
                dp[x][y] = (s[x] == s[y]);
            else
                /**
                 *
                 * if s[x+1:y-1] is palindromic and s[x] = s[y],
                 * s[x:y] is also palindromic.
                 *
                 */
                dp[x][y] = (s[x]==s[y] && dp[x+1][y-1]);

            if (dp[x][y] && (y-x > end-beg)) {
                beg = x;
                end = y;
            }
        }

        /* make sure s is *not* empty */
        bool isPalindromic(const string& s) {
            st i = 0, j = s.size() - 1;
            while (i < j) {
                if (s[i] == s[j]) {
                    ++i; --j;
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        }
};
bool Solution::dp[MAX_LENTH][MAX_LENTH];

int main() {
    vector<string> svec = {"xlx", "xllx", "xlxlx", "xlxlxxxx"};
    Solution solution;
    for ( auto s : svec ) {
        cout << s << "\t" << solution.longestPalindrome(s) << endl;
    }
    return 0;
}
