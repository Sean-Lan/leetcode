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
#include <numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0L);
        int n = nums.size();
        return (long long)n*(n+1)/2-sum;
    }
};

int main() {
    return 0;
}
