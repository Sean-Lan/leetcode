/**
 *
 * Sean
 * 2016-03-28
 *
 * https://leetcode.com/problems/plus-one/
 *
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            std::reverse(digits.begin(), digits.end());
            int cnt = 0, tmp;
            ++digits[0];
            for (auto &i : digits) {
                tmp = i+cnt;
                i = tmp%10;
                cnt = tmp/10;
                if (!cnt) break;
            }
            if (cnt) digits.push_back(1);
            return vector<int>(digits.rbegin(), digits.rend());
        }
};

int main() {}
