/**
 *
 * Sean
 * 2017-07-16
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/#/description
 *
 * Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 *
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;

        int cnt = 0;
        bool isSpace = true;

        for (auto c : s) {
            if (isspace(c)) {
                isSpace = true;
            } else if (isSpace == true) {
                ++cnt;
                isSpace = false;
            }
        }

        return cnt;
    }
};

int main() {
    return 0;
}
