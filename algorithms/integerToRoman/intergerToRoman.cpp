/**
 *
 * Sean
 * 2016-01-22
 *
 * https://leetcode.com/problems/integer-to-roman/
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            /**
             *
             * Divide the problem into separate sub-problem according to 
             * the value of num, and then solve it recursively.
             *
             */
            return handle1000_3999(num);
        }

    private:
        string handle1000_3999(int num) {
            string romanNumeral = "";
            while (num >= 1000) {
                romanNumeral += 'M';
                num -= 1000;
            }
            romanNumeral += handle0_999(num);
            return romanNumeral;
        }

        string handle0_999(int num) {
            string romanNumeral = "";
            if (num >= 900) {
                romanNumeral += "CM";
                num -= 900;
            } else if (num >= 500) {
                romanNumeral += 'D';
                num -= 500;
            }
            romanNumeral += handle0_499(num);
            return romanNumeral;
        }
        
        string handle0_499(int num) {
            string romanNumeral = "";
            if (num >= 400) {
                romanNumeral += "CD";
                num -= 400;
            } else while (num >= 100) {
                romanNumeral += 'C';
                num -= 100;
            }
            romanNumeral += handle0_99(num);
            return romanNumeral;
        }

        string handle0_99(int num) {
            string romanNumeral = "";
            if (num >= 90) {
                romanNumeral += "XC";
                num -= 90;
            } else if (num >= 50) {
                romanNumeral += 'L';
                num -= 50;
            }
            romanNumeral += handle0_49(num);
            return romanNumeral;
        }

        string handle0_49(int num) {
            string romanNumeral = "";
            if (num >= 40) {
                romanNumeral += "XL";
                num -= 40;
            } else while (num >= 10) {
                romanNumeral += 'X';
                num -= 10;
            }
            romanNumeral += handle0_10(num);
            return romanNumeral;
        }

        string handle0_10(int num) {
            static string valueTable[] = {
                "", "I", "II", "III", "IV", "V", 
                "VI", "VII", "VIII","IX"
            };
            return valueTable[num];
        }
};

int main() {
    Solution s;
    cout << 3999 << " " << s.intToRoman(3999) << endl;
    cout << 98 << " " << s.intToRoman(98) << endl;
    cout << 100 << " " << s.intToRoman(100) << endl;
    cout << 20 << " " << s.intToRoman(20) << endl;
}
