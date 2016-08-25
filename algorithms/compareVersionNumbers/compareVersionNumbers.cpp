/**
 *
 * Sean
 * 2016-08-25
 *
 * https://leetcode.com/problems/compare-version-numbers/
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int i = 0;
        int j = 0;
        int num1 = 0;
        int num2 = 0;
        while (i < len1 || j < len2) {
            while (i < len1 && version1[i] != '.') {
                num1 = 10*num1 + version1[i]-'0';
                ++i;
            }
            while (j < len2 && version2[j] != '.') {
                num2 = 10*num2 + version2[j]-'0';
                ++j;
            }
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            num1 = 0;
            num2 = 0;
            ++i;
            ++j;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    string version1 = "01";
    string version2 = "1";
    cout << solution.compareVersion(version1, version2) << endl;
    return 0;
}
