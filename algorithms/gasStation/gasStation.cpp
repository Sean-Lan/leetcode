/**
 *
 * Sean
 * 2016-07-06
 *
 * https://leetcode.com/problems/gas-station/
 *
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// Greedy
// `start` is the start point to begin the journey, `total` is the total gas left from
// the first station to current one, and `tank` is the gas left from `start` station.
// If `tank` is less than zero, we should try to begin the journey at the next station.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int start = 0;
        int tank = 0;
        int len = (int)gas.size();
        for (int i=0; i<len; ++i) {
            int delta = gas[i] - cost[i];
            total += delta;
            tank += delta;
            if (tank < 0) {
                tank = 0;
                start = i+1; // move to next
            }
        }
        return total>=0 ? start : -1;
    }
};

int main() {}
