/**
 *
 * Sean
 * 2016-06-26
 *
 * https://leetcode.com/problems/pascals-triangle/
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows > 0) {
            vector<vector<int>> result(numRows, {1});
            for (int i=1; i<numRows; ++i) {
                for (int j=1; j<result[i-1].size(); ++j)
                    result[i].push_back(result[i-1][j-1]+result[i-1][j]);
                result[i].push_back(1);
            }
            return result;
        }
        return {};
    }
};

int main() {}
