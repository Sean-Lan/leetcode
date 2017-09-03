/**
 *
 * Sean
 * 2017-09-03
 *
 * https://leetcode.com/problems/validate-ip-address/description/
 *
 * Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
 *
 * IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
 *
 * Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
 *
 * IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
 *
 * However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
 *
 * Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
 *
 * Note: You may assume there is no extra space or special characters in the input string.
 *
 * Example 1:
 * Input: "172.16.254.1"
 *
 * Output: "IPv4"
 *
 * Explanation: This is a valid IPv4 address, return "IPv4".
 * Example 2:
 * Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
 *
 * Output: "IPv6"
 *
 * Explanation: This is a valid IPv6 address, return "IPv6".
 * Example 3:
 * Input: "256.256.256.256"
 *
 * Output: "Neither"
 *
 * Explanation: This is neither a IPv4 address nor a IPv6 address.
 *
 */
#include <iostream>
#include <string>
using namespace std;

// kind of pythonic, divide a big problem into small problems.
class Solution {
    bool isValidIPv4Section(const string &section) {
        if (section.empty() || section.size() > 3) return false;
        for (auto c : section) if (!isdigit(c)) return false;
        if (section == "0") return true;

        if (section[0] == '0') return false;
        int value = atoi(section.c_str());
        return value > 0 && value <= 255;
    }

    bool isValidIPv4(const string &IP) {
        int s = 0;
        int n = IP.size();
        for (int i=0; i<n; ++i) {
            if (IP[i] == '.') {
                if (!isValidIPv4Section(IP.substr(s, i-s))) return false;
                s = i+1;
            }
        }
        return isValidIPv4Section(IP.substr(s));
    }

    bool isValidIPv6Section(const string &section) {
        if (section.empty() || section.size() > 4) return false;
        for (auto c : section) if (!(c >='0' && c<='9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return false;
        return true;
    }

    bool isValidIPv6(const string &IP) {
        int s = 0;
        int n = IP.size();
        for (int i=0; i<n; ++i) {
            if (IP[i] == ':') {
                if (!isValidIPv6Section(IP.substr(s, i-s))) return false;
                s = i+1;
            }
        }
        return isValidIPv6Section(IP.substr(s));
    }
public:
    string validIPAddress(string IP) {
        int dotCnt = 0, colonCnt = 0;
        for (auto c : IP) {
            if (c == '.') ++dotCnt;
            else if(c == ':') ++colonCnt;
        }

        if (dotCnt == 3 && isValidIPv4(IP)) return "IPv4";
        if (colonCnt == 7 && isValidIPv6(IP)) return "IPv6";
        return "Neither";
    }
};

int main() {
    return 0;
}
