/**
 *
 * Sean
 * 2016-12-24
 *
 * https://leetcode.com/problems/heaters/
 *
 * Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
 *
 * Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
 *
 * So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
 *
 * Note:
 * Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
 * Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
 * As long as a house is in the heaters' warm radius range, it can be warmed.
 * All the heaters follow your radius standard and the warm radius will the same.
 *
 * Example 1:
 * Input: [1,2,3],[2]
 * Output: 1
 * Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
 *
 * Example 2:
 * Input: [1,2,3,4],[1,4]
 * Output: 1
 * Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// binary search
class Solution {
    int lastLessThan(vector<int> &nums, int val) {
        int start = 0;
        int end = nums.size() - 1;
        // FFFFFFFTTTTT
        while (start < end) {
            int mid = start + (end-start+1)/2;
            if (nums[mid] >= val) {
                end = mid - 1;
            } else {
                start = mid;
            }
        }
        if (nums[start] >= val) return -1;
        return start;
    }

    int firstNoLessThan(vector<int> &nums, int val) {
        int start = 0;
        int end = nums.size() - 1;
        // FFFFFTTTTT
        while (start < end) {
            int mid = start + (end-start)/2;
            if (nums[mid] >= val) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        if (nums[start] < val) return -1;
        return start;
    }

public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int index, radius;
        int minRadius = 0;
        for (auto pos : houses) {
            index = lastLessThan(heaters, pos);
            radius = INT_MAX;
            if (index != -1) {
                radius = pos - heaters[index];
            }
            index = firstNoLessThan(heaters, pos);

            if (index != -1) {
                radius = min(radius, heaters[index]-pos);
            }
            minRadius = max(minRadius, radius);
        }
        return minRadius;
    }
};

int main() {
    return 0;
}
