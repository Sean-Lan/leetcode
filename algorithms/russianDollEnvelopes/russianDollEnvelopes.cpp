/**
 *
 * Sean
 * 2017-07-10
 *
 * https://leetcode.com/problems/russian-doll-envelopes/#/description
 *
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
 *
 * What is the maximum number of envelopes can you Russian doll? (put one inside other)
 *
 * Example:
 * Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 *
 */
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// O(n*log(n))
// first sort by width ascending, and height descending
// then find the longest increasing subsequence of the height in the sorted array
// Note that equal width of height doesn't work for envelopes, so the binary_search's predicate use >= instead of >
class Solution {
    // FFFFTTTTTT
    int binary_search(int s,  int e, function<bool(int)> p) {
        int mid;
        while (s < e) {
            mid = s + (e - s)/2;
            if (p(mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
            if (p1.first != p2.first) return p1.first < p2.first;
            return p1.second > p2.second;
        });

        int n = envelopes.size();


        // table[i] means the min end value of increasing subsequence with length i+1
        vector<int> table(n, INT_MAX);
        int maxLen = 1;
        table[0] = envelopes[0].second;
        for (int i=1; i<n; ++i) {
            int idx = binary_search(0, i, [&](int x) {
                return table[x] >= envelopes[i].second;
            });
            table[idx] = envelopes[i].second;
            maxLen = max(maxLen, idx+1);
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    vector<pair<int, int>> envelopes = {
        {2, 10}, {3, 20}, {4, 30}, {5, 40}
    };

    cout << solution.maxEnvelopes(envelopes) << endl;
    return 0;
}
