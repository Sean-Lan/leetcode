/**
 *
 * Sean
 * 2017-02-05
 *
 * https://leetcode.com/problems/max-consecutive-ones/
 *
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 *
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 *  The maximum number of consecutive 1s is 3.
 *
 * Note:
 *
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 */
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int curMax = 0;
        for (auto &i : nums) {
            if (i == 1) {
                ++curMax;
            } else {
                maxOnes = max(curMax, maxOnes);
                curMax = 0;
            }
        }
        maxOnes = max(curMax, maxOnes);
        return maxOnes;
    }
};

int main() {
    return 0;
}
