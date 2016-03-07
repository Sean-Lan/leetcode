/**
 *
 * Sean
 * 2016-03-07
 *
 * https://leetcode.com/problems/add-binary/
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            string result;
            for (auto &c : a) c-='0';
            for (auto &c : b) c-='0';
            int i = 0;
            int cnt = 0;
            int tmp = 0;
            for (; i<a.size()&&i<b.size(); ++i) {
                tmp = a[i] + b[i] + cnt;
                result.push_back(tmp&1);
                cnt = tmp/2;
            }
            for (int j=i; j<a.size(); ++j) {
                tmp = a[j] + cnt;
                result.push_back(tmp&1);
                cnt = tmp/2;
            }
            for (int j=i; j<b.size(); ++j) {
                tmp = b[j] + cnt;
                result.push_back(tmp&1);
                cnt = tmp/2;
            }
            if (cnt) result.push_back(cnt);
            for (auto &c : result) c+='0';
            reverse(result.begin(), result.end());
            return result;
        }
};

int main() {
}
