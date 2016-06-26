/**
 *
 * Sean
 * 2016-06-26
 *
 * https://leetcode.com/problems/pascals-triangle-ii/
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex >= 0) {
            vector<int> result(rowIndex+1, 1);
            for (int i=1; i<=rowIndex; ++i) {
                for (int j=i-1; j>0; --j)
                    result[j] += result[j-1];
            }
            return result;
        }
        return {};
    }
};

int main() {}
