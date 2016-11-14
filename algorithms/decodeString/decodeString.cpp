/**
 *
 * Sean
 * 2016-11-14
 *
 * https://leetcode.com/problems/decode-string/
 *
 * Given an encoded string, return it's decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> cntStack;
        string res;
        string curStr; // current part string start and end of `s` or inside a certain `[]`
        int cur = 0;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                if (cur == 0 && !curStr.empty()) {
                    if (cntStack.empty()) {
                            res += curStr;
                        } else {
                            strStack.push(curStr);
                        }
                    curStr = "";
                }
                cur = cur*10 + c-'0';
                continue;
            }
            if (c == '[') {
                cntStack.push(cur);
                cur = 0;
                continue;
            }
            if (c == ']') {
                int cnt = cntStack.top();
                cntStack.pop();
                string part = curStr;
                for (int i=0; i<cnt-1; ++i) {
                    curStr += part;
                }

                if (!strStack.empty()) {
                    part = strStack.top();
                    strStack.pop();
                    curStr = part + curStr;
                }
                continue;
            }
            curStr.push_back(c);
        }
        // add remaining part
        if (!curStr.empty()) res += curStr;
        return res;
    }
};

int main() {
    Solution solution;
    string s = "3[a]2[bc]";
    cout << solution.decodeString(s) << endl;
    return 0;
}
