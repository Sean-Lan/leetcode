/**
 *
 * Sean
 * 2017-06-10
 *
 * https://leetcode.com/problems/sequence-reconstruction/#/description
 *
 * Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.
 *
 * Example 1:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3]]
 *
 * Output:
 * false
 *
 * Explanation:
 * [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
 * Example 2:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2]]
 *
 * Output:
 * false
 *
 * Explanation:
 * The reconstructed sequence can only be [1,2].
 * Example 3:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
 *
 * Output:
 * true
 *
 * Explanation:
 * The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
 * Example 4:
 *
 * Input:
 * org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
 *
 * Output:
 * true
 *
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// topo sort
// several notes:
// 1. for a sequence, we don't need to push every pair to construct the topo order, just adjacent pair is enough
// 2. need to check every number in the seqs is in the valid range
// 3. utilize the `org` array to do the check and exit earlier
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<unordered_set<int>> succs(n+1);
        vector<unordered_set<int>> pres(n+1);
        unordered_set<int> shown;

        int x, y;
        for (auto &vi : seqs) {
            if (vi.empty()) continue;
            if (vi.size() == 1) {
                x = vi[0];
                if (x < 0 || x > n) return false;
                shown.insert(x);
                continue;
            }
            x = vi[0];
            if (x < 0 || x > n) return false;
            for (int i=1; i<vi.size(); ++i) {
                x = vi[i-1];
                y = vi[i];
                if (y < 0 || y > n) return false;
                shown.insert(x);
                succs[x].insert(y);
                pres[y].insert(x);
            }
            shown.insert(y); // last one
        }

        if (shown.size() != n) return false;

        queue<int> aQueue;

        for (int i=1; i<=n; ++i) {
            if (pres[i].empty()) aQueue.push(i);
        }
        if (aQueue.size() > 1) return false;

        int freeCnt;
        int cur;
        int index = 0;
        while (!aQueue.empty()) {
            cur = aQueue.front();
            if (org[index++] != cur) return false;
            aQueue.pop();
            auto &vi = succs[cur];
            freeCnt = 0;
            for (auto i : vi) {
                pres[i].erase(cur);
                if (pres[i].empty()) {
                    if (++freeCnt > 1) return false; // not unique
                    aQueue.push(i);
                }
            }
        }

        return index == n;
    }
};
