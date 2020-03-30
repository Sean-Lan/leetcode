/**
 *
 * Sean
 * 2020-03-30
 *
 * https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 *
 * Given a non-negative integer num, return the number of steps to reduce it to zero. If the current
 * number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
 *
 * Example 1:
 *
 * Input: num = 14
 * Output: 6
 * Explanation:
 * Step 1) 14 is even; divide by 2 and obtain 7.
 * Step 2) 7 is odd; subtract 1 and obtain 6.
 * Step 3) 6 is even; divide by 2 and obtain 3.
 * Step 4) 3 is odd; subtract 1 and obtain 2.
 * Step 5) 2 is even; divide by 2 and obtain 1.
 * Step 6) 1 is odd; subtract 1 and obtain 0.
 * Example 2:
 *
 * Input: num = 8
 * Output: 4
 * Explanation:
 * Step 1) 8 is even; divide by 2 and obtain 4.
 * Step 2) 4 is even; divide by 2 and obtain 2.
 * Step 3) 2 is even; divide by 2 and obtain 1.
 * Step 4) 1 is odd; subtract 1 and obtain 0.
 * Example 3:
 *
 * Input: num = 123
 * Output: 12
 *
 * Constraints:
 *
 * 0 <= num <= 10^6
 *
 */
#include <iostream>

using namespace std;

// take the number in binary.
// if the current digit is 1, we need 2 steps to remove it.
//    1. -1
//    2. /2 (right shift 1 bit)
// if the current digit is 0, we need 1 step to remove it.
//    1. /2 (right shift 1 bit)
class Solution {
public:
    int numberOfSteps (int num) {
        if (num == 0) return 0;
        int cnt = 0;
        while (num) {
            if (num & 1) cnt += 2;
            else ++cnt;
            num >>= 1;
        }
        -- cnt;
        return cnt;
    }
};

int main() {
  Solution solution;
  int cnt = solution.numberOfSteps(123);
  cout << cnt << endl;
  return 0;
}
