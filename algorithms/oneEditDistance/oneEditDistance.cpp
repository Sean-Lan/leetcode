/**
 *
 * Sean
 * 2017-05-21
 *
 * https://leetcode.com/problems/one-edit-distance/#/description
 *
 * Given two strings S and T, determine if they are both one edit distance apart.
 *
 */
#include <iostream>
using namespace std;

// only two cases need to consider:
// 1) m == n: count the different characters.
// 2) m == n+1: find the first different character then skip it
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n) return isOneEditDistance(t, s); // make sure m is longer than n
        if (m - n > 1) return false;
        if (m == n) {
            int diffCnt = 0;
            for (int i=0; i<m; ++i) {
                if (s[i] != t[i]) {
                    ++diffCnt;
                    if (diffCnt > 1) return false;
                }
            }
            return diffCnt == 1;
        } else { // m = n - 1;
            int pos = -1;
            for (int i=0; i<n; ++i) {
                if (s[i] != t[i]) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) return true;
            for (int i=pos; i<n; ++i) {
                if (s[i+1] != t[i]) return false;
            }
            return true;
        }
    }
};

int main() {
    return 0;
}
