/**
 *
 * Sean
 * 2017-07-28
 *
 * https://leetcode.com/problems/russian-doll-envelopes/tabs/description
 *
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
 *
 * What is the maximum number of envelopes can you Russian doll? (put one inside other)
 *
 * Example:
 * Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 *
 */
#include <vector>
#include <utility>
using namespace std;

// DP O(n^2)
// dp[i] means the maximum length of increasing sequences ends with i-th envelope
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
            if (p1.first != p2.first) return p1.first < p2.first;
            return p1.second > p2.second;
        });

        int n = envelopes.size();

        vector<int> dp(n, 1);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLen = 1;
        for (auto &i : dp) maxLen = max(maxLen, i);
        return maxLen;
    }
};


int main() {
    return 0;
}
