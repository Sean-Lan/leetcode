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
#include <vector>
using namespace std;

// DP
// O(n) time and space complexity
static const int N = 1000000007;
class Solution {
    typedef long long ll;
public:
    int checkRecord(int n) {
        vector<int> sum(n+1, 0);
        sum[0] = 1;
        sum[1] = 2;
        // last[0] ends with P, last[1] ends with only one L, last[2] ends with LL
        vector<int> last = {1, 1, 0};
        vector<int> cur(3, 0);

        for (int i=2; i<=n; ++i) {
            cur[0] = ((last[0] + last[1]) % N + last[2]) % N;
            cur[1] = last[0];
            cur[2] = last[1];
            sum[i] = ((cur[0] + cur[1]) % N + cur[2]) % N;
            last = cur;
        }

        int res = sum[n]; // without an 'A'
        for (int i = 0; i<n; ++i) { // insert an 'A' into a certain position
            res += ((ll)sum[i] * sum[n-1-i]) % N;
            res %= N;
        }
        return res;
    }
};

int main() {
    return 0;
}
