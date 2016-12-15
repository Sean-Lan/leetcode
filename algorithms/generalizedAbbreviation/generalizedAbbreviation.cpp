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
    // lastAlpha is a boolean flag to control alphabetical and numerica characters showing alternatively
    void dfs(vector<string> &result, string &current, int index, const string &word, bool lastAlpha) {
        int n = word.size();
        if (index == n) {
            result.push_back(current);
            return;
        }
        
        if (lastAlpha) {
            for (int i=index; i<n; ++i) {
                string num = to_string(i-index+1);
                current += num;
                dfs(result, current, i+1, word, false);
                for (int i=0; i<num.size(); ++i)
                    current.pop_back();
            }
        } else {
            for (int i=index; i<n; ++i) {
                for (int j=index; j<=i; ++j)
                    current.push_back(word[j]);
                dfs(result, current, i+1, word, true);
                for (int j=index; j<=i; ++j)
                    current.pop_back();
            }
        }
    }
    
   
public:
    vector<string> generateAbbreviations(string word) {
        if (word.empty()) return {""};
        vector<string> result;
        string current;
        dfs(result, current, 0, word, false);
        dfs(result, current, 0, word, true);
        return result;
    }
};

int main() {
    return 0;
}
