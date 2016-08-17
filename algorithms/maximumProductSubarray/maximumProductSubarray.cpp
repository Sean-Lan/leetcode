/**
 *
 * Sean
 * 2016-08-17
 *
 * https://leetcode.com/problems/maximum-product-subarray/
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// O(1) space complexity and O(n) time complexity.
class Solution {
    typedef long long ll;
    typedef vector<ll> vll;
    static const int NEGATIVE = -1;
    static const int POSITIVE = 1;
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // Either lastMinNegative equals POSITIVE or lastMaxPositive equals NEGATIVE means it's impossible.
        ll lastMinNegative = POSITIVE;
        ll lastMaxPositive = NEGATIVE;
        ll globalMax = nums[0];
        for (int i=0; i<n; ++i) {
            if (nums[i] > 0) {
                lastMinNegative = (lastMinNegative >= 0) ? POSITIVE : lastMinNegative*nums[i];
                lastMaxPositive = (lastMaxPositive <= 0) ? nums[i] : lastMaxPositive*nums[i];
            } else if (nums[i] < 0) {
                lastMinNegative = (lastMaxPositive <= 0) ? nums[i] : lastMaxPositive*nums[i];
                lastMaxPositive = (lastMinNegative >= 0) ? NEGATIVE : lastMinNegative*nums[i];
            } else {
                lastMinNegative = 0;
                lastMaxPositive = 0;
            }
            if (lastMaxPositive >= 0)
                globalMax = max(globalMax, lastMaxPositive);
        }
        return globalMax;
    }
};

int main() {
    vector<int> iVec = { -2 };
    Solution solution;
    cout << solution.maxProduct(iVec) << endl;
}
