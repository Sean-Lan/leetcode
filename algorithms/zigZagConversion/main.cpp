/**
 *
 * Sean
 * 2015-05-02
 *
 * https://leetcode.com/problems/zigzag-conversion/
 *
 * pattern on a given number of rows like this: (you may want to display this 
 * pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number 
 * of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 */

#include <iostream>
#include <string>
using namespace std;

#define DEBUG

class Solution {
    public:
        /**
         * 
         * Use an 2-D array to save the zigzag tranverse, then, visit the array 
         * from top to down and left to right.
         *
         */
        string convert(string s, int numRows) {
            if (numRows == 1)
                return s;
            char **arr = new char*[numRows];
            for (int i=0; i<numRows; i++)
                arr[i] = new char[s.size()];
            for (int i=0; i<numRows; i++)
                for (int j=0; j<s.size(); j++)
                    arr[i][j] = -1;

            string::size_type cnt = 0;
            bool skewed = false;
            int i = 0,j=0;
            while (cnt != s.size()) {
                if (!skewed)
                    arr[i++][j] = s[cnt++];
                else
                    arr[i--][j++] = s[cnt++];

                if (i==-1) {
                    skewed = false;
                    i = 1; --j;
                    continue;
                }
                if (i==numRows) {
                    skewed = true;
                    i = numRows - 2; ++j;
                    continue;
                }
            }
            string converted;
            for (int i=0; i<numRows; ++i)
                for (int j=0; j<s.size(); ++j)
                    if (arr[i][j] != -1) 
                        converted.push_back(arr[i][j]);
#ifdef DEBUG 
            for (int i=0; i<numRows; ++i) {
                for (int j=0; j<s.size(); ++j)
                        cout << ((arr[i][j]!=-1)?arr[i][j]:' ');
                cout << endl;
            }
#endif
            for (int i=0; i<numRows; ++i)
                delete[] arr[i];
            delete[] arr;
            return converted;
        }
};

int main() {
    string s = "PAYPALISHIRING";
    Solution solution;
    cout << solution.convert(s, 2) << endl;
}
