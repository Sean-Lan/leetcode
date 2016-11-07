/**
 *
 * Sean
 * 2016-11-07
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 *
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 * Note: You may assume the string contain only lowercase letters.
 *
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnts(26, 0);
        for (auto c : s) {
            ++cnts[c - 'a'];
        }
        for (int i=0; i<s.size(); ++i) {
            if (cnts[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main() { return 0; }
