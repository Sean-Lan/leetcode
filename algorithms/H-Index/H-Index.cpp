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

// binary search
class Solution {
    // TTTTT...TTFFFFFF
    // find the last index of T
    int bs_search(int s, int e, function<bool(int)> p) {
        int m;
        while (s < e) {
            if (s+1 == e) {
                if (p(e)) return e;
                return s;
            }
            m = s + (e-s)/2;
            if (p(m)) {
                s = m;
            } else {
                e = m - 1;
            }
        }
        return s;
    }
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        if (citations.front() == 0) return 0; // make sure the answer is in range(0, size-1)
        return bs_search(0, citations.size()-1, [&] (int i) {
            return citations[i] >= i+1;
        })+1;
    }
};

int main() {
    return 0;
}
