/**
 *
 * Sean
 * 2017-09-23
 *
 * https://leetcode.com/problems/add-bold-tag-in-string/description/
 *
 * Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
 *
 * Example 1:
 * Input:
 * s = "abcxyz123"
 * dict = ["abc","123"]
 * Output:
 * "<b>abc</b>xyz<b>123</b>"
 *
 * Example 2:
 * Input:
 * s = "aaabbcc"
 * dict = ["aaa","aab","bc"]
 * Output:
 * "<b>aaabbc</b>c"
 *
 * Note:
 * The given dict won't contain duplicates, and its length won't exceed 100.
 * All the strings in input have length in range [1, 1000].
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// O(n*m*w): n = len(s), m = len(dict), w = len(word)
// Event based
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> cnts(n+1, 0);

        for (auto &w : dict) {
            auto pos = s.find(w);
            int sz = w.size();
            while (pos != string::npos) {
                ++ cnts[pos];
                -- cnts[pos + sz];
                pos = s.find(w, pos+1);
            }
        }

        int cnt = 0;
        bool bold = false;
        string res;
        for (int i=0; i<n; ++i) {
            cnt += cnts[i];
            if (cnt && !bold) {
                res += "<b>";
                bold = true;
            }
            if (!cnt && bold) {
                res += "</b>";
                bold = false;
            }
            res += s[i];
        }
        if (cnt) res += "</b>";
        return res;
    }
};

int main() {
    return 0;
}
