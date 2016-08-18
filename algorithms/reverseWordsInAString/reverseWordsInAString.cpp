/**
 *
 * Sean
 * 2016-08-18
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 *
 * click to show clarification.
 *
 * Clarification:
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 *
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 *
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 *
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// O(n) space and time complexity.
class Solution {
    public:
    void reverseWords(string &s) {
            istringstream is(s);
            string aWord;
            ostringstream os;
            vector<string> sVec;
            while (is >> aWord) {
                sVec.push_back(aWord);
            }
            for (auto it = sVec.rbegin(); it != sVec.rend(); ++it)
                os << *it << " ";
            s = os.str();
            if (!s.empty())
                s.pop_back();
        }
};

int main() {
    string s = "  the sky is blue  ";
    Solution solution;
    solution.reverseWords(s);
    cout << s << endl;
    return 0;
}
