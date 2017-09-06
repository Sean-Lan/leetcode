/**
 *
 * Sean
 * 2017-09-06
 *
 * https://leetcode.com/problems/text-justification/
 *
 * Given an array of words and a length L, format the text such that each line has exactly L characters
 * and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
 * Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible.
 * If the number of spaces on a line do not divide evenly between words,
 * the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 *
 *  Corner Cases:
 *  A line other than the last line might contain only one word. What should you do in this case?
 *  In this case, that line should be left-justified.
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void printResult(const vector<string> &result) {
    for (auto &s : result)
        cout << s << endl;
    cout << endl;
}

class Solution {
    string format(vector<string> &words, int s, int e, bool left, int maxWidth) {
        string res;
        if (left) {
            for (int i=s; i<=e; ++i) {
                if (i!=s) res += ' ';
                res += words[i];
            }
            while (res.size() < maxWidth) res.push_back(' ');
            return res;
        }

        int cumSum = 0;
        for (int i=s; i<=e; ++i) cumSum += words[i].size();
        int base = (maxWidth - cumSum) / (e-s);
        int r = (maxWidth - cumSum) % (e-s);
        res= words[s];
        for (int i=s+1; i<=e; ++i) {
            for (int j=0; j<base; ++j) res += ' ';
            if (r) { r--; res += ' '; }
            res += words[i];
        }
        return res;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int cumLength = 0;
        int s = 0, e;
        while (s < n) {
            cumLength = words[s].size();
            e = s+1;
            while (e < n) {
                cumLength += 1 + words[e].size();
                if (cumLength > maxWidth) {
                    --e;
                    break;
                }
                ++e;
            }
            if (e == n) e = n-1;
            bool left = e == n-1 || e == s;
            res.push_back(format(words, s, e, left, maxWidth));
            s = e+1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> words = { "Don't","go","around","saying","the","world","owes",
        "you","a","living;","the","world","owes","you","nothing;","it","was","here","first." };
    auto result = solution.fullJustify(words, 30);
    printResult(result);
}
