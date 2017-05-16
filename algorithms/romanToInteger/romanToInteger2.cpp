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
#include <vector>
using namespace std;

vector<string> table[4] = {
    {"MMM", "MM", "M"},
    {"CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C"},
    {"XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X"},
    {"IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I"}
};

// try to find thousands-, hundreds-, tens, and ones- places of the number 
// the order of the check matters
class Solution {
    bool startsWith(string &s, string &p, int beg) {
        int m = s.size();
        int n = p.size();
        if (m - beg < n) return false;
        for (int i=0; i<n; ++i) {
            if (s[i+beg] != p[i]) return false;
        }
        return true;
    }
public:
    int romanToInt(string s) {
        int n = s.size();
        int res = 0;
        int cur = 0;
        
        // 1000
        vector<string>& thousandPrefixes = table[0];
        for (int i = 0; i<3; ++i) {
            if (startsWith(s, thousandPrefixes[i], cur)) {
                res += 1000 * (3-i);
                cur = thousandPrefixes[i].size();
                break;
            }
        }
        
        // 100
        vector<string>& hundredPrefixes = table[1];
        for (int i=0; i<9; ++i) {
            if (startsWith(s, hundredPrefixes[i], cur)) {
                res += 100 * (9-i);
                cur += hundredPrefixes[i].size();
                break;
            }
        }
        
        // 10
        vector<string>& tenPrefixes = table[2];
        for (int i=0; i<9; ++i) {
            if (startsWith(s, tenPrefixes[i], cur)) {
                res += 10 * (9-i);
                cur += tenPrefixes[i].size();
                break;
            }
        }
        
        // 1
        vector<string>& onePrefixes = table[3];
        for (int i=0; i<9; ++i) {
            if (startsWith(s, onePrefixes[i], cur)) {
                res += 9-i;
                break;
            }
        }
        
        return res;
    }
};

int main() {
    return 0;
}
