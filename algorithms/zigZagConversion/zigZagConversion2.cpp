/**
 *
 * Sean
 * 2017-04-16
 *
 * https://leetcode.com/problems/zigzag-conversion/#/description
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> sVec(numRows);
        int cur = 0;
        bool forward = true;
        for (auto c : s) {
            sVec[cur].push_back(c);
            if (forward) {
                if (cur == numRows-1) {
                    forward = false;
                    -- cur;
                } else {
                    ++ cur;
                }
            } else {
                if (cur == 0) {
                    forward = true;
                    ++ cur;
                } else {
                    -- cur;
                }
            }
        }
        string res;
        for (auto &aStr : sVec) res += aStr;
        return res;
    }
};

int main() {
    return 0;
}
