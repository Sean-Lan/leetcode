/**
 * 
 * Sean
 * 2015-08-14
 *
 * https://leetcode.com/problems/palindrome-number/
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */

#include <iostream>
using namespace std;

class Solution {
    public:
        /**
         * Every time get the leftmost and rightmost digit and compare them.
         * *Note*: power must be divided by 100 in every loop since two digits are
         * removed in one loop.
         */
        bool isPalindrome(int x) {
            int left, right, power;
            if (x < 0)
                return false;
            power = findPowerOfTen(x);
            while (x) {
                left = x / power;
                right = x % 10;
                if ( left != right) 
                    return false;
                x -= left * power;
                x /= 10;
                power /= 100;
            } 
            return true;
        }
    private:
        int findPowerOfTen(int x) {
            int power = 1;
            while ( (x/power) >= 10) {
                // Please make sure power doesn't overflow
                power *= 10;
            } 
            return power;
        }
};

int main() {
    Solution s;
    cout << s.isPalindrome(-1) << endl;
    cout << s.isPalindrome(12321) << endl;
    cout << s.isPalindrome(3) << endl;
    cout << s.isPalindrome(32) << endl;
    cout << s.isPalindrome(1000000001) << endl;
}

