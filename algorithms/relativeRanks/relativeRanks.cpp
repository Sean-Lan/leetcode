/**
 *
 * Sean
 * 2017-03-19
 *
 * https://leetcode.com/problems/relative-ranks/#/description
 *
 * Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 *
 * Example 1:
 *   Input: [5, 4, 3, 2, 1]
 *   Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 *   Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
 *   For the left two athletes, you just need to output their relative ranks according to their scores.
 *
 * Note:
 *   N is a positive integer and won't exceed 10,000.
 *   All the scores of athletes are guaranteed to be unique.
 *
 */
#include <string>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// index sort
class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& nums) {
            int n = nums.size();
            vector<int> indexes(n);
            iota(indexes.begin(), indexes.end(), 0);
            sort(indexes.begin(), indexes.end(), [&nums](int i, int j) {
                    return nums[i] > nums[j]; 
                    });

            vector<string> res(n);
            for (int i=0; i<n; ++i) {
                if (i == 0) {
                    res[indexes[i]] = "Gold Medal";
                } else if (i == 1) {
                    res[indexes[i]] = "Silver Medal";
                } else if (i == 2) {
                    res[indexes[i]] = "Bronze Medal";
                } else {
                    res[indexes[i]] = to_string(i+1);
                }
            }
            return res;
        }
};
