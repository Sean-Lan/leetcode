/**
 *
 * Sean
 * 2016-01-24
 *
 * https://leetcode.com/problems/longest-common-prefix/
 *
 * Write a function to find the longest common prefix string
 * amongst an array of strings.
 *
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) return "";
            string::size_type currentPos = 0;
            string prefix;
            char currentChar;
            bool isFirst = true;
            bool isSame = true;
            while (true) {
                for (auto &str : strs) {
                    if (str.size() == currentPos) {
                        isSame = false;
                        break;
                    }
                    if (isFirst) {
                        currentChar = str[currentPos];
                        isFirst = false;
                    } else if (str[currentPos] != currentChar) {
                        isSame = false;
                        break;
                    }
                }
                isFirst = true;
                ++currentPos;
                if (isSame)
                    prefix.push_back(currentChar);
                else
                    break;
            }
            return prefix;
        }
};

int main() {
    vector<string> strs = {
        ""
    };
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    strs.clear();
    cout << s.longestCommonPrefix(strs) << endl;
}
