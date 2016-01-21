/**
 *
 * Sean
 * 2016-01-21
 *
 * https://leetcode.com/problems/roman-to-integer/
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

const unordered_map<char, int> valueTable {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
};

class Solution {
    public:
        int romanToInt(string s) {
            return romanToInt(s.cbegin(), s.cend());
        }
    private:
        typedef string::const_iterator string_cit;
        /**
         *
         * First try to find the largest number in s,
         * then divide the problem into left, max, right.
         * The value is max - left + right.
         *
         */
        int romanToInt(string_cit beg, string_cit end) {
            if (beg == end)
                return 0;
            if (next(beg) == end) {
                return valueTable.find(*beg)->second;
            }
            int max = -1;
            string_cit maxIt;
            int value;
            for (auto it = beg; it!=end; ++it) {
                value = valueTable.find(*it)->second;
                if(max < value) {
                    max = value;
                    maxIt = it;
                }
            }
            int leftValue = romanToInt(beg, maxIt);
            int rightValue = romanToInt(next(maxIt), end);
            return max - leftValue + rightValue;
        }
};

int main() {
    Solution s;
    cout << s.romanToInt("CMXCIX") << endl;
    cout << s.romanToInt("MDCCCLXXXVIII") << endl;
    cout << s.romanToInt("MMMCMXCIX") << endl;
}
