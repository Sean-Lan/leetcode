/**
 *
 * Sean
 * 2017-06-03
 *
 * https://leetcode.com/problems/strobogrammatic-number-ii/#/description
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * For example,
 * Given n = 2, return ["11","69","88","96"].
 *
 */
#include <string>
#include <vector>
using namespace std;

char strob[] = {'0', '1', '8'};

char valid[] = {'0', '1', '6', '9', '8'};

inline char getStrob(char c) {
    if (c == '0') return '0';
    if (c == '1') return '1';
    if (c == '8') return '8';
    if (c == '6') return '9';
    if (c == '9') return '6';
    return -1;
}

string getStrobNumber(string s) {
    string res;
    int n = s.size();
    for (int i = n-1; i>=0; --i)
        res.push_back(getStrob(s[i]));
    return res;
}

// backtracking
class Solution {
    void dfs(string &cur, vector<string> &partial, int n) {
        if (cur.size() == n) {
            // note*: any number starts with 0 is NOT valid
            if (n && cur[n-1] == '0') return;
            partial.push_back(cur);
            return;
        }
        for (auto c : valid) {
            cur.push_back(c);
            dfs(cur, partial, n);
            cur.pop_back();
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        vector <string> partial;
        string cur;

        dfs(cur, partial, n/2);

        vector<string> res;

        for (auto &s : partial) {
            if (n & 1) {
                for (auto c : strob) {
                    res.push_back(getStrobNumber(s) + c + s);
                }
            } else {
                res.push_back(getStrobNumber(s) + s);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
