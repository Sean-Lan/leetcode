/**
 *
 * Sean
 * 2016-12-01
 *
 * https://leetcode.com/problems/sparse-matrix-multiplication/
 *
 * Given two sparse matrices A and B, return the result of AB.
 *
 * You may assume that A's column number is equal to B's row number.
 *
 * Example:
 *
 * A = [
 *   [ 1, 0, 0],
 *   [-1, 0, 3]
 * ]
 *
 * B = [
 *   [ 7, 0, 0 ],
 *   [ 0, 0, 0 ],
 *   [ 0, 0, 1 ]
 * ]
 *
 *
 *      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
 * AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
 *                   | 0 0 1 |
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty()) return {};
        // compress A by rows
        unordered_map<int, vector<pair<int, int>>> compressedA;
        int m = A.size();
        int n = A[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]) compressedA[i].push_back({j, A[i][j]});
            }
        }

        // compress B by columns
        unordered_map<int, vector<pair<int, int>>> compressedB;
        m = B.size();
        n = B[0].size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (B[j][i]) compressedB[i].push_back({j, B[j][i]});
            }
        }

        vector<vector<int>> C(A.size(), vector<int>(B[0].size()));
        for (auto &aRow : compressedA) {
            int rowIndex = aRow.first;
            auto &rowValues = aRow.second;
            for (auto &aCol : compressedB) {
                int colIndex = aCol.first;
                auto &colValues = aCol.second;
                int sum = 0;
                int i=0, j=0;
                while (i<rowValues.size() && j<colValues.size()) {
                    auto &a_value = rowValues[i];
                    auto &b_value = colValues[j];
                    if (a_value.first < b_value.first) {
                        ++i;
                    } else if (a_value.first > b_value.first) {
                        ++j;
                    } else {
                        sum += a_value.second * b_value.second;
                        ++i; ++j;
                    }
                }
                C[rowIndex][colIndex] = sum;
            }
        }
        return C;
    }
};

int main() {
    return 0;
}
