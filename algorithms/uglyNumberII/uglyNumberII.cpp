/**
 *
 * Sean
 * 2016-03-04
 *
 * https://leetcode.com/problems/ugly-number-ii/
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;

/**
 *
 * Dynamic programming.
 * Use indexAndValues array to record the index and currentResult of numbers in the uglyNumbers array
 * that has been mutiplied by 2, 3, 5 separately.
 * The main process is comprised by two parts:
 * 1. Advance each record so that it is greater than the current maximum ugly number.
 * 2. Find the smallest one and push it into uglyNumbers.
 *
 */
vector<int> uglyNumbers = {1};
const int values[3] = {2,3,5};

// (index, currentResult)
pair<size_t, int> indexAndValues[3] = { {0,2}, {0,3}, {0,5} };

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<=uglyNumbers.size())
            return uglyNumbers[n-1];
        int cur = uglyNumbers[uglyNumbers.size()-1];
        while (uglyNumbers.size()<n) {
            // first check and advance indexAndValues
            for (int i=0; i<3; ++i)
                while (indexAndValues[i].second <= cur)
                    indexAndValues[i].second = uglyNumbers[++indexAndValues[i].first] * values[i];
            // find the minimum of the three
            int mininum = std::numeric_limits<int>::max();
            for (int i=0; i<3; ++i)
                mininum = min(mininum, indexAndValues[i].second);
            cur = mininum;
            uglyNumbers.push_back(mininum);
        }
        return uglyNumbers[n-1];
    }
};
int main() {
    Solution s;
    /* for (int i=1; i<20; ++i) */
        /* cout << s.nthUglyNumber(i) << endl; */
    cout << s.nthUglyNumber(1352) << endl;
}
