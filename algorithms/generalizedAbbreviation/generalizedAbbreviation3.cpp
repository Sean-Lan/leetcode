/**
 *
 * Sean
 * 2016-12-15
 *
 * https://leetcode.com/problems/generalized-abbreviation/
 *
 * Write a function to generate the generalized abbreviations of a word.
 *
 * Example:
 *
 * Given word = "word", return the following list (order does not matter):
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 *
 */
#include <vector>
#include <string>
using namespace std;

// bit manipulation
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = (1 << word.size());
        vector<string> result;
        auto l = [&word](int mask) {
            int cnt = 0;
            string res;
            for (int i=0; i<word.size(); ++i) {
                if (mask & (1<<i)) {
                    if (cnt) {
                        res += to_string(cnt);
                        cnt = 0;
                    }
                    res += word[i];
                } else {
                    ++cnt;
                }
            }
            if (cnt) res += to_string(cnt);
            return res;
        };
        
        for (int i=0; i<n; ++i) {
            result.push_back(l(i));
        }
        return result;
    }
};

int main() {
    return 0;
}
