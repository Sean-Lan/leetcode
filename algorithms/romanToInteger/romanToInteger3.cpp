/**
 *
 * Sean
 * 2017-05-16
 *
 * https://leetcode.com/problems/roman-to-integer/#/description
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

unordered_map<char, int> table = {
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
        int res = 0;
        // we need to do subtraction only if the following character combinations show
        if (s.find("IV") != string::npos) res -= 2;
        if (s.find("IX") != string::npos) res -= 2;
        if (s.find("XL") != string::npos) res -= 20;
        if (s.find("XC") != string::npos) res -= 20;
        if (s.find("CD") != string::npos) res -= 200;
        if (s.find("CM") != string::npos) res -= 200;
        
        for (auto c : s) res += table[c];

        return res;
    }
};

int main() {
    return 0;
}
