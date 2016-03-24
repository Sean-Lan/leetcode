/**
 *
 * Sean
 * 2016-03-24
 *
 * https://leetcode.com/problems/palindrome-partitioning/
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 *
 *   [
 *     ["aa","b"],
 *     ["a","a","b"]
 *   ]
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// DFS with backtracking
class Solution {
    public:
        vector<vector<string>> partition(string s) {
            if (s.empty()) return {};
            vector<string> current;
            vector<vector<string>> result;
            helper(current, s, 0, result);
            return result;
        }
    private:
        void helper(vector<string> &current, const string& s, int pos,
               vector<vector<string>> &result) {
            if (pos == s.size()) {
                result.push_back(current);
                return;
            }
            int len = s.size();
            for (int i=pos; i<len; ++i) {
                string _str = s.substr(pos, i-pos+1);
                if (!isPalindrome(_str)) continue;
                current.push_back(_str);
                helper(current, s, i+1, result);
                current.pop_back();
            }
        }

        bool isPalindrome(const string &s) {
            int i=0, j=s.size()-1;
            while (i<j) {
                if (s[i]!=s[j])
                    return false;
                ++i; --j;
            }
            return true;
        }
};

void printResult(const vector<vector<string>> &result) {
    for (auto &sVec : result) {
        for (auto &s : sVec)
            cout << s << " ";
        cout << endl;
    }
}

int main() {
    Solution solution;
    string s = "aab";
    auto result = solution.partition(s);
    printResult(result);
}
