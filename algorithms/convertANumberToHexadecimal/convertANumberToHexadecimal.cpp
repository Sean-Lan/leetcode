/**
 *
 * Sean
 * 2016-10-06
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 *
 * Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
 *
 * Note:
 *
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed integer.
 * You must not use any method provided by the library which converts/formats the number to hex directly.
 * Example 1:
 *
 * Input:
 * 26
 *
 * Output:
 * "1a"
 * Example 2:
 *
 * Input:
 * -1
 *
 *  Output:
 *  "ffffffff"
 *
 */
#include <iostream>
#include <string>
using namespace std;

// bit manipulation
class Solution {
    static const char TABLE[16];
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        short index;
        for (int i=0; i<8; ++i) {
            index = num&0xf;
            num >>= 4;
            result.push_back(TABLE[index]);
        }

        while (result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

const char Solution::TABLE[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f'};

int main() {
    Solution solution;
    cout << solution.toHex(0) << endl;
    cout << solution.toHex(-1) << endl;
    cout << solution.toHex(5) << endl;
    cout << solution.toHex(std::numeric_limits<int>::max()) << endl;
    cout << solution.toHex(std::numeric_limits<int>::min()) << endl;
    return 0;
}
