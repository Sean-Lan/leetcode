/**
 *
 * Sean
 * 2016-10-27
 *
 * https://leetcode.com/problems/third-maximum-number/
 *
 * Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 *
 * Example 1:
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 * Example 2:
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * Example 3:
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// *NOTE* need to care about INT_MIN in nums.
class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            vector<long long> maxNumber(3, LLONG_MIN);
            for (auto &num : nums) {
                if (num > maxNumber[0]) {
                    maxNumber[2] = maxNumber[1];
                    maxNumber[1] = maxNumber[0];
                    maxNumber[0] = num;
                } else if (num > maxNumber[1]) {
                    if (num != maxNumber[0]) {
                        maxNumber[2] = maxNumber[1];
                        maxNumber[1] = num;
                    }
                } else if (num > maxNumber[2]) {
                    if (num != maxNumber[1]) {
                        maxNumber[2] = num;
                    }
                }
            }
            return maxNumber[2] != LLONG_MIN ? maxNumber[2] : maxNumber[0];
        }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    cout << solution.thirdMax(nums) << endl;
    return 0;
}
