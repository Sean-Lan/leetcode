/**
 *
 * Sean
 * 2017-08-28
 *
 * https://leetcode.com/problems/student-attendance-record-ii/description/
 *
 * Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.
 *
 * A student attendance record is a string that only contains the following three characters:
 *
 * 'A' : Absent.
 * 'L' : Late.
 * 'P' : Present.
 * A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * Example 1:
 * Input: n = 2
 * Output: 8
 * Explanation:
 * There are 8 records with length 2 will be regarded as rewardable:
 * "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
 * Only "AA" won't be regarded as rewardable owing to more than one absent times.
 * Note: The value of n won't exceed 100,000.
 *
 */
#include <iostream>
using namespace std;

// O(n) time complexity and O(1) space complexity
// ailj means the string contains i `a`s, and ends with l `l`s.
// refer to the solution with state diagram
static const int N = 1000000007;
class Solution {
    typedef long long ll;
public:
    int checkRecord(int n) {
        ll _a1l0 = 1, _a1l1 = 0, _a1l2 = 0, _a0l0 = 1, _a0l1 = 1, _a0l2 = 0;
        ll a1l0, a1l1, a1l2, a0l0, a0l1, a0l2;
        for (int i=1; i<n; ++i) {
            a1l0 = (_a0l0 + _a0l1 + _a0l2 + _a1l0 + _a1l1 + _a1l2) % N;
            a1l1 = _a1l0;
            a1l2 = _a1l1;
            a0l0 = (_a0l0 + _a0l1 + _a0l2) % N;
            a0l1 = _a0l0;
            a0l2 = _a0l1;

            _a1l0 = a1l0;
            _a1l1 = a1l1;
            _a1l2 = a1l2;
            _a0l0 = a0l0;
            _a0l1 = a0l1;
            _a0l2 = a0l2;
        }
        return (_a1l0 + _a1l1 + _a1l2 + _a0l0 + _a0l1 + _a0l2) % N;
    }
};

int main() {
    return 0;
}
