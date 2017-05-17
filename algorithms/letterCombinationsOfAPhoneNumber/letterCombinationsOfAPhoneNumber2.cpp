/**
 *
 * Sean
 * 2017-05-17
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<string> table = {
    " ",
    "_",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

// iterative solution with a queue.
// every time append all the possible characters corresponding to the certain digit to all possible strings without using the those characters, and push the generated string into the queue
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        queue<string> aQueue;
        aQueue.push("");
        int n = digits.size();
        for (int i = 0; i<n; ++i) {
            string &possibleChars = table[digits[i]-'0'];
            while (true) {
                string cur = aQueue.front();
                if (cur.size() == i) {
                    aQueue.pop();
                    for (auto c : possibleChars) {
                        aQueue.push(cur + c);
                    }
                } else {
                    break;
                }
            }

        }
        while (!aQueue.empty()) {
            res.push_back(aQueue.front());
            aQueue.pop();
        }
        return res;
    }
};

int main() {
    return 0;
}
