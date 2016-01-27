/**
 *
 * Sean
 * 2016-01-27
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 */

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

unordered_map<char, vector<string>> numMap = {
    {'1', {"_"}},
    {'2', {"a","b","c"}},
    {'3', {"d","e","f"}},
    {'4', {"g","h","i"}},
    {'5', {"j","k","l"}},
    {'6', {"m","n","o"}},
    {'7', {"p","q","r","s"}},
    {'8', {"t","u","v"}},
    {'9', {"w","x","y","z"}},
    {'0', {" "}}
};

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if (digits.size()==0) return {};
            if (digits.size()==1) return numMap[digits[0]];

            vector<string> result;
            auto sVec = letterCombinations(digits.substr(0, digits.size()-1));
            auto& letters = numMap[digits[digits.size()-1]];
            for (string& s : sVec) {
                for (string& letter: letters) {
                    result.push_back(s+letter);
                }
            }
            return result;
        }
};


void printResult (vector<string> & result) {
    for (auto& s : result)
        cout << s << endl;
}

int main() {
    string digits = "23";
    Solution s;
    auto result = s.letterCombinations(digits);
    printResult(result);
}
