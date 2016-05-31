/**
 *
 * Sean
 * 2016-05-31
 *
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array 
 * such that nums[i] = nums[j] and the difference between i and j is at most k.
 *
 */
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

// use hash table to store the last shown position of a certain number.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        int size = nums.size();
        for (int i=0; i<size; ++i) {
            if (table.find(nums[i]) != table.end()) {
                if (i-table[nums[i]] <= k)
                    return true;
            }
            table[nums[i]] = i;
        }
        return false;
    }
};

int main() {}
