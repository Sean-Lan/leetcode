/**
 *
 * Sean
 * 2017-07-29
 *
 * https://leetcode.com/problems/count-the-repetitions/tabs/description
 *
 * Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".
 *
 * On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.
 *
 * You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.
 *
 * Example:
 *
 * Input:
 * s1="acb", n1=4
 * s2="ab", n2=2
 *
 * Return:
 * 2
 *
 */
#include <vector>
#include <string>
using namespace std;

// DP
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        int sz1 = s1.size(), sz2 = s2.size();

        // nextIndex[i] means search s1 with the i-th character of s2,
        // the next character of s2 to be searched after tranversing s1
        vector<int> nextIndex(sz2, -1);
        // count[i] means search s1 with the i-th character of s2,
        // how many times reaching the end of s2 after tranversing s1
        vector<int> count(sz2, 0);

        // at most sz2 times iterations
        int cur = 0;
        while (nextIndex[cur] < 0) {
            int enterIndex = cur;
            for (int j=0; j<sz1; ++j) {
                if (s1[j] == s2[cur]) {
                    ++cur;
                    if (cur == sz2) {
                        cur = 0;
                        ++count[enterIndex];
                    }
                }
            }
            nextIndex[enterIndex] = cur;
        }

        int repeatStart = cur;
        // find the period `t`
        cur = nextIndex[cur];
        int t = 1;
        // the number of s2 can be found in a period
        int repeatCnt = count[cur];
        while (cur != repeatStart) {
            cur = nextIndex[cur];
            repeatCnt += count[cur];
            ++t;
        }

        int cnt = 0;
        cur= 0;
        while (n1) { // in case of n1 equals 0
            -- n1;
            cnt += count[cur];
            cur = nextIndex[cur];
            if (cur == repeatStart) { // repeation begins
                cnt += n1/t * repeatCnt;
                n1 %= t;
            }
        }

        return cnt/n2;
    }
};

int main() {
    return 0;
}
