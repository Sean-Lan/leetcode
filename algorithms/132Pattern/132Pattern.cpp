/**
 *
 * Sean
 * 2016-11-19
 *
 * https://leetcode.com/problems/132-pattern/
 *
 * Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
 *
 * Note: n will be less than 15,000.
 *
 * Example 1:
 * Input: [1, 2, 3, 4]
 *
 * Output: False
 *
 * Explanation: There is no 132 pattern in the sequence.
 * Example 2:
 * Input: [3, 1, 4, 2]
 *
 * Output: True
 *
 * Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
 * Example 3:
 * Input: [-1, 3, 2, 0]
 *
 * Output: True
 *
 * Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 *
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Reference to https://discuss.leetcode.com/topic/67881/single-pass-c-o-n-space-and-time-solution-8-lines-with-detailed-explanation
// From end to start, `ak` stores its current possible maximum value.
// If find `ai` large than `ak`, push `ai` into stack, pop out the values less than `ai`, and reset `ak` to the new maximum value.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<int> aStack;
        int ak = INT_MIN;
        int ai;
        for (int i = n-1; i>=0; --i) {
            ai = nums[i];
            if (ak > ai) return true;
            while (!aStack.empty()) {
                if (aStack.top() < ai) {
                    ak = aStack.top();
                    aStack.pop();
                } else {
                    break;
                }
            }
            aStack.push(ai);
        }
        return false;
    }
};

int main() {
    return 0;
}
