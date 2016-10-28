/**
 *
 * Sean
 * 2016-10-28
 *
 * https://leetcode.com/problems/nth-digit/
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n < 231).
 *
 * Example 1:
 *
 * Input:
 * 3
 *
 * Output:
 * 3
 * Example 2:
 *
 * Input:
 * 11
 *
 * Output:
 * 0
 *
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    typedef long long ll;
public:
    int findNthDigit(int n) {
        int i;
        ll cnt;
        // count the number of digits of the number n-th digit falls in.
        for (i=1, cnt=9; n > cnt*i; ++i) {
            n -= cnt*i;
            cnt *= 10;
        }

        // calculate the number
        cnt /= 9;
        cnt *= i;
        bool isFirst = true;
        vector<int> num;
        for (int j= 0; j<i; ++j) {
            int k = 0;
            if (isFirst) {
                k = 1;
                isFirst = false;
            }
            for (; k<=9 && n > cnt; ++k) {
                n -= cnt;
            }
            num.push_back(k);
            cnt /= 10;
        }

        // return the n-th digit.
        return num[n-1];
    }
};

int main() {
    Solution solution;
    cout << solution.findNthDigit(11) << endl;
    return 0;
}
