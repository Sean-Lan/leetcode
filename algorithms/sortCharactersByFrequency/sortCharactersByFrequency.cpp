/**
 *
 * Sean
 * 2016-12-29
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/
 *
 * Given a string, sort it in decreasing order based on the frequency of characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 */
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

// hash table + set
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for (auto c : s) {
            ++counts[c];
        }
        auto cmp = [&counts](char c1, char c2) {
            int cnt1 = counts[c1], cnt2 = counts[c2];
            if (cnt1 != cnt2)
                return cnt1 > cnt2;
            return c2 > c1;
        };
        set<char, decltype(cmp)> aSet(cmp);
        for (auto &aPair : counts) {
            aSet.insert(aPair.first);
        }
        string res;
        int cnt;
        for (auto c : aSet) {
            cnt = counts[c];
            for (int i=0; i<cnt; ++i) {
                res.push_back(c);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
