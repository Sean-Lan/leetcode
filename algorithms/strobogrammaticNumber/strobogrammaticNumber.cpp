/**
 *
 * Sean
 * 2017-06-03
 *
 * https://leetcode.com/problems/strobogrammatic-number/#/description
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 *
 * Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 *
 * For example, the numbers "69", "88", and "818" are all strobogrammatic.
 *
 */
#include <iostream>
#include <string>
using namespace std;

inline char getStro(char c) {
    if (c == '0') return '0';
    if (c == '1') return '1';
    if (c == '6') return '9';
    if (c == '9') return '6';
    if (c == '8') return '8';
    return -1;
}

bool isStro(char c) {
    return c == '0' || c == '1' || c == '8';
}
class Solution {
public:
    bool isStrobogrammatic(string num) {
        string stro;
        char c;
        int n = num.size();
        for (int i=0, j=n-1; i<j; ++i, --j) {
            c = getStro(num[i]);
            if (c != num[j]) return false;
        }
        if (n & 1) return isStro(num[n>>1]);
        return true;
    }
};

int main() {
    return 0;
}
