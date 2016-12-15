/**
 *
 * Sean
 * 2016-12-15
 *
 * https://leetcode.com/problems/sort-transformed-array/
 *
 * Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.
 *
 * The returned array must be in sorted order.
 *
 * Expected time complexity: O(n)
 *
 * Example:
 * nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
 *
 * Result: [3, 9, 15, 33]
 *
 * nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
 *
 * Result: [-23, -5, 1, 7]
 *
 */
#include <vector>
using namespace std;

// two pointers, from two sides to the center.
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result;
        
        auto f = [&a, &b, &c](int x) {
            return a*x*x + b*x + c;
        };
        
        int n = nums.size();
        if (a == 0) {
            for (auto i : nums)
                result.push_back(f(i));
            if (b < 0)
                reverse(result.begin(), result.end());
        } else {
            int p1 = 0, p2 = n-1;
            int val1, val2;
            while (p1 <= p2) {
                val1 = f(nums[p1]);
                val2 = f(nums[p2]);
                if ((a<0 && val1 < val2) || (a>0 && val1 > val2)) {
                    result.push_back(val1);
                    ++p1;
                } else {
                    result.push_back(val2);
                    --p2;
                }
            }
        }
        if (a > 0) reverse(result.begin(), result.end());
        return result;
    }
};
