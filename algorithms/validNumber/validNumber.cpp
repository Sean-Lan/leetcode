/**
 *
 * Sean
 * 2016-03-27
 *
 * https://leetcode.com/problems/valid-number/
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 *
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        bool isNumber(string s) {
            if (s.empty()) return false;
            int start = 0, end = s.size()-1;
            while (start<=end && s[start]==' ') ++start;
            while (start<=end && s[end]==' ') --end;
            if (start > end) return false;
            string trimed = s.substr(start, end-start+1);
            if (isNumeric(trimed)) return true;
            int ie = 0;
            for (ie=0; ie<trimed.size(); ++ie)
                if (trimed[ie] == 'e') break;

            if (ie == trimed.size()) return false;

            string leftPart = trimed.substr(0, ie);
            string rightPart = trimed.substr(ie+1);
            return isNumeric(leftPart) && isInteger(rightPart);
        }
    private:
        bool isNumeric(string &s) {
            if (s.empty()) return false;
            if (s[0]=='+' || s[0]=='-') s = s.substr(1);
            if (s.empty()) return false;
            bool pointed = false;
            for (auto &c : s) {
                if (!((c>='0'&&c<='9')||c=='.')) return false;
                if (c == '.') {
                    if (pointed) return false;
                    pointed = true;
                }
            }
            if (pointed && s.size()==1) return false;
            return true;
        }

        bool isInteger(string &s) {
            if (s.empty()) return false;
            if (s[0]=='+' || s[0]=='-') s = s.substr(1);
            if (s.empty()) return false;
            for (auto &c: s) if(c<'0'||c>'9') return false;
            return true;
        }
};

int main() {
    Solution solution;
    cout << solution.isNumber(" 2ee10  ") << endl;
    cout << solution.isNumber(" 1.3.5") << endl;
    cout << solution.isNumber("6e6.5") << endl;
}
