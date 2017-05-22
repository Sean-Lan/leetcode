/**
 *
 * Sean
 * 2017-05-22
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/#/description
 *
 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 *
 * For example, Given s = “eceba”,
 *
 * T is "ece" which its length is 3.
 *
 */
#include <string>
using namespace std;


// O(n)
// i0: the start index of the valid substring
// i1: the start index of the first kind character from the end
// i2: the start index of the second kind character from the end
// e.g., aaabbbaaa: i0 - 0, i1 - 3, i2 - 6
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n < 3) return n;

        int maxLen = 2;
        char c1, c2;
        c1 = s[0];
        c2 = -1;
        int i0, i1, i2;
        i0 = i1 = 0;
        i2 = -1;

        char c;
        for (int i=1; i<n; ++i) {
            c = s[i];
            if (c == c1) {
                if (c2 == -1) continue;
                else {
                    i1 = i2;
                    i2 = i;
                    swap(c1, c2);
                }
            } else if (c == c2) {
                continue;
            } else {
                if (c2 == -1) {
                    c2 = c;
                    i2 = i;
                } else {
                    c1 = c2;
                    c2 = c;
                    maxLen = max(maxLen, i-i0);
                    i0 = i1 = i2;
                    i2 = i;
                }
            }
        }
        if (i2 == -1) return n;
        maxLen = max(maxLen, n - i0);
        return maxLen;
    }
};

int main() {
    return 0;
}
