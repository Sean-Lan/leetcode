/**
 *
 * Sean
 * 2016-12-13
 *
 * https://leetcode.com/problems/missing-number/
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 *
 */
#include <vector>
using namespace std;

// bit manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int number = 0;
        for (auto &i : nums)
            number ^= i;
        int n = nums.size();
        for (int i=1; i<=n; ++i)
            number ^= i;
        return number;
    }
};

int main() {
    return 0;
}
