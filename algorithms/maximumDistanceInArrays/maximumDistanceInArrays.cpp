/**
 *
 * Sean
 * 2017-08-17
 *
 * https://leetcode.com/problems/maximum-distance-in-arrays/description/
 *
 * Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.
 *
 * Example 1:
 * Input:
 * [[1,2,3],
 *  [4,5],
 *  [1,2,3]]
 * Output: 4
 * Explanation:
 * One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
 * Note:
 * Each given array will have at least 1 number. There will be at least two non-empty arrays.
 * The total number of the integers in all the m arrays will be in the range of [2, 10000].
 * The integers in the m arrays will be in the range of [-10000, 10000].
 *
 */
#include <vector>
using namespace std;

// O(n)
// keep updating the maximum and minimum value in the previous array,
// calculating the distance with the tranversal
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int curMin = arrays[0].front();
        int curMax = arrays[0].back();
        int n = arrays.size();
        for (int i=1; i<n; ++i) {
            res = max(res, arrays[i].back() - curMin);
            res = max(res, curMax - arrays[i].front());
            curMin = min(curMin, arrays[i].front());
            curMax = max(curMax, arrays[i].back());
        }
        return res;
    }
};

int main() {
    return 0;
}
