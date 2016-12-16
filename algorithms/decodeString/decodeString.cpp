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
        string current;
        int cnt = 0;
        for (auto c : s) {
            if (isdigit(c)) {
                if (cnt) {
                    cnt = 10*cnt + c-'0';
                } else {
                    // first digit character, push the current string into strStack
                    cnt = c - '0';
                    strStack.push(current);
                    current = "";
                }
            } else if (c == '[') {
                cntStack.push(cnt);
                cnt = 0;
            } else if (c == ']') {
                int lastCnt = cntStack.top();
                cntStack.pop();
                string tmp;
                // repeat the current string lastCnt times
                for (int i=0; i<lastCnt; ++i)
                    tmp += current;
                // append the prevoius part
                string lastStr = strStack.top();
                strStack.pop();
                current = lastStr + tmp;
            } else {
                current.push_back(c);
            }
        }
        return current;
    }
};

int main() {
    Solution solution;
    string s = "3[a]2[bc]";
    cout << solution.decodeString(s) << endl;
    return 0;
}
