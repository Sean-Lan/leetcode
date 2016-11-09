/**
 *
 * Sean
 * 2016-11-09
 *
 * https://leetcode.com/problems/reverse-string/
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 *
 */
#include <string>
using namespace std;

class Solution {
    public:
    string reverseString(string s) {
            return string(s.rbegin(), s.rend());
        }
};

int main() { return 0; }
