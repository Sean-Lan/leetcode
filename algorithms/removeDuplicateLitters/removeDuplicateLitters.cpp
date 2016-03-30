/**
 *
 * Sean
 * 2016-03-30
 *
 * https://leetcode.com/problems/remove-duplicate-letters/
 *
 * Given a string which contains only lowercase letters, remove duplicate letters so that every
 * letter appear once and only once. You must make sure your result is the smallest in
 * lexicographical order among all possible results.
 *
 * Example:
 * Given "bcabc"
 * Return "abc"
 *
 * Given "cbacdcbc"
 * Return "acdb"
 *
 */
#include <iostream>
using namespace std;

// First count all the characters in s.
// Then, use greedy algorithm. The result string itself can be a stack.
// Remember remeber to initialize the arr in a funtion.
class Solution {
    public:
        string removeDuplicateLetters(string s) {
            int counts[26] = {0};
            for (auto &c : s)
                ++counts[c-'a'];

            bool added[26] = {false};
            string result;
            char lastOne;
            for (const auto c: s) {
                --counts[c-'a'];
                if (added[c-'a'])
                    continue;
                while (!result.empty() && (lastOne=*result.rbegin())>c && counts[lastOne-'a']) {
                    result.pop_back();
                    added[lastOne-'a'] = false;
                }
                added[c-'a'] = true;
                result.push_back(c);
            }
            return result;
        }
};

int main() {
    Solution solution;
    string s = "thesqtitxyetpxloeevdeqifkz";
    cout << s << endl;
    cout << solution.removeDuplicateLetters(s) << endl;
}
