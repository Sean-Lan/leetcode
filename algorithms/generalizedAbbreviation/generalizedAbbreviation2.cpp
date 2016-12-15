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

class Solution {
    // cnt is used to count the number of skipped characters
    // For each character, we either skip it or keep it
    void dfs(vector<string> &result, string &current, int index, int cnt, string word) {
        int n = word.size();
        if (index == n) {
            if (cnt > 0) {
                string num = to_string(cnt);
                current += num;
                result.push_back(current);
                for (int i=0; i<num.size(); ++i) current.pop_back();
            } else {
                result.push_back(current);
            }
            return;
        }

        // just skip it
        dfs(result, current, index+1, cnt+1, word);
        // keep it
        if (cnt > 0) {
            string num = to_string(cnt);
            current += num;
            current.push_back(word[index]);
            dfs(result, current, index+1, 0, word);
            current.pop_back();
            for (int i=0; i<num.size(); ++i) current.pop_back();
        } else {
            current.push_back(word[index]);
            dfs(result, current, index+1, 0, word);
            current.pop_back();
        }
    }
    public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        string current;
        dfs(result, current, 0, 0, word);
        return result;
    }
};

int main() {
    return 0;
}
