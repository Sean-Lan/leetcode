/**
 *
 * Sean
 * 2016-09-12
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// use two pointers.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        vector<int> result;
        while (start < end) {
            if (numbers[start] + numbers[end] < target)
                ++ start;
            else if (numbers[start] + numbers[end] > target)
                -- end;
            else
                break;
        }
        result.push_back(start+1);
        result.push_back(end+1);
        return result;
    }
};

int main() {
    return 0;
}
