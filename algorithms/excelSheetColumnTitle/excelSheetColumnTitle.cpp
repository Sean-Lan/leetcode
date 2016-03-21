/**
 *
 * Sean
 * 2016-03-21
 *
 * https://leetcode.com/problems/excel-sheet-column-title/
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *    1 -> A
 *    2 -> B
 *    3 -> C
 *    ...
 *    26 -> Z
 *    27 -> AA
 *    28 -> AB
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// n in [26*k+1..26*k+26]
// let n be xxx..xX, the remainer part be xxx..x
// Then remainer part = (n-1)/26
class Solution {
    public:
        string convertToTitle(int n) {
            string title;
            int tmp = 0;
            char newChar;
            // invariant: n is the ordinal of the remainer part.
            while (n) {
                tmp = n%26;
                if (tmp == 0)
                    newChar = 'Z';
                else
                    newChar = 'A'-1+tmp;
                title.push_back(newChar);
                n = (n-1)/26;
            }
            reverse(title.begin(), title.end());
            return title;
        }
};

int main() {
    Solution solution;
    auto title = solution.convertToTitle(28);
    cout << title << endl;

    title = solution.convertToTitle(26);
    cout << title << endl;

    title = solution.convertToTitle(52);
    cout << title << endl;
}
