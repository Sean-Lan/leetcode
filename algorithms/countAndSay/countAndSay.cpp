/**
 *
 * Sean
 * 2016-02-23
 *
 * https://leetcode.com/problems/count-and-say/
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string currentStr = "1";
            string resultStr = "1";
            int cnt;
            for (int i=1; i<n; ++i) {
                resultStr.clear();
                int j=0;
                while (true) {
                    cnt = 1;
                    while (j+1<currentStr.size() && currentStr[j]==currentStr[j+1]) {
                        ++cnt;
                        ++j;
                    }
                    resultStr.push_back('0'+cnt);
                    resultStr.push_back(currentStr[j]);
                    if (++j == currentStr.size())
                        break;
                }
                currentStr = resultStr;
            }
            return resultStr;
        }
};

int main() {
    Solution s;
    for (int i=1; i<10; ++i)
        cout << s.countAndSay(i) << endl;
    return 0;
}
