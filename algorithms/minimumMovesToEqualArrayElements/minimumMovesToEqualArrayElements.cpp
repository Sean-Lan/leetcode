/**
 *
 * Sean
 * 2016-11-21
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 *
 * Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 3
 *
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 *
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// increasing n-1 elements by 1 has the same effort of decreasing the element by 1.
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long minValue = *min_element(nums.begin(), nums.end());
        long long res = 0;
        for (auto &i : nums) {
            res += i-minValue;
        }
        return res;
    }
};

int main() {
    return 0;
}
