/**
 *
 * Sean
 * 2015-05-03
 *
 * https://leetcode.com/problems/reverse-integer/
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * Some spoilers:
 * If the integer's last digit is 0, what should the output be? ie, cases such as 
 * 10, 100.
 *
 * Did you notice that the reversed integer might overflow? Assume the input is a 
 * 32-bit integer, then the reverse of 1000000003 overflows. How should you handle 
 * such cases?
 *
 * For the purpose of this problem, assume that your function returns 0 when the 
 * reversed integer overflows.
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
    public:
        /**
         *
         * Use istringstream and ostringstream to handle integer reverse.
         * Use long long to reserve the converted one, and compare it with 
         * predefined value INT_MAX and INT_MIN to check whether it overflows.
         *
         */
        int reverse(int x) {
            string raw;
            ostringstream os;

            os << x;
            raw = os.str();

            bool negative = false;
            if (raw[0] == '-')
                negative = true;

            string reversed;
            string::reverse_iterator rbeg = raw.rbegin();
            string::reverse_iterator rend = raw.rend();
            while (rbeg!=rend && *rbeg == '0')
                ++rbeg;
            
            if (rbeg == rend)   // Special case for 0
                return 0;

            if (negative) {
                --rend;
                reversed.push_back('-');
            }
            copy(rbeg, raw.rend(), back_inserter(reversed));

            istringstream is(reversed);
            long long reversed_int;
            is >> reversed_int;
            if (reversed_int <= INT_MAX && reversed_int >= INT_MIN)
                return reversed_int;
            else                // Overflow
                return 0;
        }
};

int main() {
    cout << INT_MAX<< " " << INT_MIN << endl;
    Solution solution;
    cout << solution.reverse(-2) << endl;
    cout << solution.reverse(1000000003) << endl;
    cout << solution.reverse(-103300) << endl;
    cout << solution.reverse(0) << endl;
    return 0;
}
