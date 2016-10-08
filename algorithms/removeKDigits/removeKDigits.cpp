/**
 *
 * Sean
 * 2016-10-08
 *
 * https://leetcode.com/problems/remove-k-digits/
 *
 * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
 *
 * Note:
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * Example 1:
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 * Example 2:
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 * Example 3:
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 *
 */
#include <list>
#include <vector>
#include <iostream>
using namespace std;

/**
 *
 * Greedy algorithm.
 * O(n) where n is the length of num.
 * Find the last number from head which is monotonic increasing and ease it.
 *
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        list<char> listNum;
        for (auto c : num) listNum.push_back(c);
        for (auto it = listNum.begin(); it!=listNum.end() && k;) {
            if (next(it) != listNum.end()) {
                if (*it > *(next(it))) {
                    --k;
                    if (it == listNum.begin()) {
                        listNum.erase(it);
                        it = listNum.begin();
                    } else {
                        listNum.erase(it--);
                    }
                } else {
                    ++it;
                }
            } else {
                --k;
                if (it == listNum.begin()) {
                    listNum.erase(it);
                    it = listNum.begin();
                } else {
                    listNum.erase(it--);
                }
            }
        }
        while (!listNum.empty() && listNum.front() == '0') listNum.pop_front();
        if (listNum.empty()) return "0";
        string res;
        for (auto c : listNum) res.push_back(c);
        return res;
    }
};

int main() {
    return 0;
}
