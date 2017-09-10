/**
 *
 * Sean
 * 2017-09-10
 *
 * Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
 *
 * Example 1:
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * Example 2:
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 * Note:
 * The given number is in the range [0, 10^8]
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// `pos` records the last shown index of a certain digit
// for each digit from the most significant, check whether there is a digit behind it > it
// if so swap them and return
class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        int n = number.size();

        vector<int> pos(10, 0);
        for (int i=0; i<n; ++i) {
            pos[number[i]-'0'] = i;
        }

        for (int i=0; i<n; ++i) {
            int cur = number[i]-'0';
            for (int j=9; j>cur; --j) {
                if (pos[j] > i) {
                    swap(number[i], number[pos[j]]);
                    return atoi(number.c_str());
                }
            }
        }
        return num;
    }
};

int main() {
    return 0;
}
