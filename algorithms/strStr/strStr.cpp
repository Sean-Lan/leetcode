/**
 *
 * Sean
 * 2016-02-06
 *
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = -1;
        bool found = true;
        for (int i=0; i+needle.size()<=haystack.size(); ++i) {
            found = true;
            for (int j=0; j<needle.size(); ++j) {
                if (needle[j] != haystack[i+j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                pos = i;
                break;
            }
        }
        return pos;
    }
};

int main() {
    string haystack = "missisipi";
    string needle = "a";
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
}
