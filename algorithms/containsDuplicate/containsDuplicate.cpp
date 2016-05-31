/**
 *
 * Sean
 * 2016-05-31
 *
 * https://leetcode.com/problems/contains-duplicate/
 *
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 *
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Hash table.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> shown;
        for (auto &i : nums) {
            if (shown.find(i) != shown.end())
                return true;
            shown.insert(i);
        }
        return false;
    }
};

int main() {}
