/**
 *
 * Sean
 * 2019-10-19
 *
 * https://leetcode.com/problems/defanging-an-ip-address/submissions/
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
 *
 * A defanged IP address replaces every period "." with "[.]".
 *
 * Example 1:
 *
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 * Example 2:
 *
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 *
 * Constraints:
 *
 * The given address is a valid IPv4 address.
 *
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (char c : address) {
            if (c == '.') {
                result += "[.]";
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

int main() {
  Solution solution;
  string address = "1.1.1.1";
  string defanged = solution.defangIPaddr(address);
  cout << defanged << endl;
}
