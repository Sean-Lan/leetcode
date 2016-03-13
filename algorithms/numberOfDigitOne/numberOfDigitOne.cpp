/**
 *
 * Sean
 * 2016-03-13
 *
 * https://leetcode.com/problems/number-of-digit-one/
 *
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> H = {1};
/**
 *
 * For a number as AX...X(i Xs in total), the 1s are from:
 *
 * part-1: the X...X part
 *      0~9...9 (i 9s in total)
 *    1 0~9...9 (i 9s in total)
 *    2 0~9...9 (i 9s in total)
 *        ...
 *  A-1 0~9...9 (i 9s in total)
 *    A 0~X...X (i Xs in total)
 *
 * part-2: the highest 1 part.
 *    if the highest digit is 1:
 *      X...X+1
 *    else
 *      10...0(i 0s in total)
 *
 * Let H(i) means the number of ones of 0~9...9(i 9s in total), then:
 *      H(i) = 10*H(i-1) + 10^(i-1)
 *  use a vector to cache the intermediate result of
 *  number of 1s of 0~9...9(H[i] means i+1 9s in total)
 *
 */
class Solution {
    public:
        int countDigitOne(int n) {
            if (n<10) return n>=1;
            int numberOfDigits = 0;
            int tmp = n;
            int highestDigit = tmp;
            while (tmp) {
                ++numberOfDigits;
                highestDigit = tmp;
                tmp/=10;
            }
            tmp = 1;
            for (int i=1; i<numberOfDigits; ++i)
                tmp *= 10;
            int ret = highestDigit*h(numberOfDigits-1);
            int r = n-highestDigit*tmp;
            ret += countDigitOne(r);
            if (highestDigit==1)
                ret += (r+1);
            else
                ret += tmp;
            return ret;
        }
    private:
        // number of 1s between 0~9..9(i 9s in total)
        int h(int index) {
            if (index<=H.size())
                return H[index-1];
            int ones = 1;
            for (int i=1; i<index; ++i) ones *=10;
            int ret = 10*h(index-1) + ones;
            H.push_back(ret);
            return ret;
        }
};

int main() {
    Solution s;
    cout << s.countDigitOne(9) << endl;
    cout << s.countDigitOne(13) << endl;
    cout << s.countDigitOne(20) << endl;
}
