/**
 *
 * Sean
 * 2017-06-14
 *
 * https://leetcode.com/problems/h-index/#/description
 *
 * Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
 *
 * For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
 *
 * Note: If there are several possible values for h, the maximum one is taken as the h-index.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// O(n) time & space complexity
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int n = citations.size();
        // counts[i] means the number of papers which has citations == i (for n, >=n)
        vector<int> counts(n+1, 0);

        for (auto &c : citations) {
            if (c > n) ++counts[n];
            else ++counts[c];
        }

        // cumCnt is the number of papers which has citations >= i
        int cumCnt = 0;
        for (int i=n; i>=0; --i) {
            cumCnt += counts[i];
            // find the largest as the h-index
            if (cumCnt >= i) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}
