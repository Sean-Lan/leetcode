/**
 *
 * Sean
 * 2016-03-21
 *
 * https://leetcode.com/problems/excel-sheet-column-number/
 *
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty()) return 0;
        int n = s[0]-'A'+1;
        // N(k+1) = N(k)*26 + s[k+1]-'A'+1
        int len = s.size();
        for (int i=1; i<len; ++i)
            n = n*26+s[i]-'A'+1;
        return n;
    }
};

int main() {
    Solution solution;
    cout << solution.titleToNumber("A") << endl;
    cout << solution.titleToNumber("Z") << endl;
    cout << solution.titleToNumber("AA") << endl;
    cout << solution.titleToNumber("AZ") << endl;
}
