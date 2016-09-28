/**
 *
 * Sean
 * 2016-09-28
 *
 * https://leetcode.com/problems/lexicographical-numbers/
 *
 * Given an integer n, return 1 - n in lexicographical order.
 *
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 *
 * Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Keep generating next number in lexicographical order.
// Reference to https://discuss.leetcode.com/topic/55184/java-o-n-time-o-1-space-iterative-solution-130ms
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int cur = 1;
        for (int i=0; i<n; ++i) {
            result.push_back(cur);
            if (cur*10 <= n) {
                cur = cur*10;
            } else if (cur%10 != 9 && cur+1 <= n) {
                ++cur;
            } else {
                while ((cur/10)%10 == 9)
                    cur /= 10;
                cur = cur/10 + 1;
            }
        }
        return result;
    }
};

int main() {}
