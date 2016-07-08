/**
 *
 * Sean
 * 2016-07-08
 *
 * https://leetcode.com/problems/super-pow/
 *
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
 *
 * Example1:
 *
 * a = 2
 * b = [3]
 *
 * Result: 8
 *
 * Example2:
 *
 * a = 2
 * b = [1,0]
 *
 * Result: 1024
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Reference to https://discuss.leetcode.com/topic/50458/1-liners-other-with-explanations
class Solution {
    static const int base = 1337;
    int power(int a, int digit) {
            int result = 1;
            for (int i=0; i<digit; ++i)
                result  = result * a % base;
            return result;
        }
    public:
    int superPow(int a, vector<int>& b) {
            int aPower = a % base; // Important! otherwise overflow.
            int result = 1;
            for (auto it = b.rbegin(); it!=b.rend(); ++it) {
                        result = result * power(aPower, *it) % base;
                        aPower = power(aPower, 10);
                    }
            return result;
        }
};

int main() {
    int a = 2147483647;
    vector<int> b {2, 0, 0};
    Solution solution;
    cout << solution.superPow(a, b) << endl;
}
