/**
 *
 * Sean
 * 2017-07-06
 *
 * https://leetcode.com/problems/valid-perfect-square/#/description
 *
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 * Example 2:
 *
 * Input: 14
 * Returns: False
 *
 */
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// O(log(num))
// binary search, find the first number x s.t. x * x >= num, then do a check for x * x == num
class Solution {
    // FFFF..FTTTT
    int binary_search(int s, int e, function<bool(int)> p) {
        int mid;
        while (s < e) {
            mid = s + (e-s)/2;
            if (p(mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
public:
    bool isPerfectSquare(int num) {
        auto p = [&num] (int x) {
            return (long long) x * x >= num;
        };
        int root = binary_search(1, num, p);
        return (long long) root * root == num;
    }
};

int main() {
    return 0;
}
