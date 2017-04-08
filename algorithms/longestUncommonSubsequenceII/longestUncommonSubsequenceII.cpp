/**
 *
 * Sean
 * 2017-04-08
 *
 * https://leetcode.com/problems/longest-uncommon-subsequence-ii/
 *
 * Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
 * 
 * A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
 * 
 * The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
 * 
 * Example 1:
 * Input: "aba", "cdc", "eae"
 * Output: 3
 * Note:
 * 
 * All the given strings' lengths will not exceed 10.
 * The length of the given list will be in the range of [2, 50].
 *
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// count, sort and compare
class Solution {
    // s1.size() <= s2.size()
    bool isSubstr(string &s1, string &s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        for (int i=0, j=0; i<len1; ++i, ++j) {
            while (j < len2 && s1[i] != s2[j]) ++j;
            if (j == len2) return false;
        }
        return true;
    }
    typedef pair<string, int> psi;
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> cnts;
        for (auto &s : strs) ++ cnts[s];
        vector<psi> cntVec(cnts.begin(), cnts.end());
        sort(cntVec.begin(), cntVec.end(), [](const psi&p1,  const psi&p2) {
            return p1.first.size() > p2.first.size();
        });
        
        int len = cntVec.size();
        for (int i=0; i<len; ++i) {
            if (cntVec[i].second == 1) {
                auto &s = cntVec[i].first;
                bool good = true;
                for (int j=0; j<i; ++j) {
                    if (isSubstr(s, cntVec[j].first)) {
                        good = false;
                        break;
                    }
                }
                if (good) return s.size();
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}
