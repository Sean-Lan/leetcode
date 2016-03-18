/**
 *
 * Sean
 * 2016-03-18
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

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> currentLine;
        int idx = 0;
        int currentLength = 0;
        int LEN = words.size();
        while (idx < LEN) {
            currentLength += (currentLine.empty())?words[idx].size():words[idx].size()+1;
            if (currentLength <= maxWidth) {
                currentLine.push_back(words[idx]);
                ++idx;
            } else {
                currentLength -= words[idx].size()+1;
                int diff = maxWidth-currentLength;
                if (currentLine.size() == 1) {
                    result.push_back(currentLine[0]+string(diff, ' '));
                } else {
                    int space = diff/(currentLine.size()-1)+1;
                    int remainder = diff%(currentLine.size()-1);
                    string aLine = currentLine[0];
                    int i=1;
                    for (; i<=remainder; ++i) {
                        aLine += string(space+1, ' ');
                        aLine += currentLine[i];
                    }
                    for (; i<currentLine.size(); ++i) {
                        aLine += string(space, ' ');
                        aLine += currentLine[i];
                    }
                    result.push_back(aLine);
                }
                currentLength = 0;
                currentLine.clear();
            }
        }

        // the last line.
        string lastLine = currentLine[0];
        for (int i=1; i<currentLine.size(); ++i) {
            lastLine.push_back(' ');
            lastLine += currentLine[i];
        }
        result.push_back(lastLine+string(maxWidth-lastLine.size(), ' '));
        return result;
    }
};

void printResult(const vector<string> &result) {
    for (auto &s : result)
        cout << s << endl;
    cout << endl;
}

int main() {
    Solution solution;
    vector<string> words = { "Don't","go","around","saying","the","world","owes",
        "you","a","living;","the","world","owes","you","nothing;","it","was","here","first." };
    auto result = solution.fullJustify(words, 30);
    printResult(result);
}
