/**
 *
 * Sean
 * 2017-06-19
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/#/description
 *
 * Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and ).
 *
 * Examples:
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 *
 */
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// BFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        vector<string> res;

        queue<string> aQueue;
        aQueue.push(s);
        visited.insert(s);
        bool found = false;
        while (!aQueue.empty()) {
            auto cur = aQueue.front();
            aQueue.pop();
            if (isValid(cur)) {
                res.push_back(cur);
                found = true;
            }
            // if found, we don't need further search since all the possible solutions with the same length
            // have already been pushed into the queue
            if (found) continue;

            for (int i=0; i<cur.size(); ++i) {
                if (cur[i] == '(' || cur[i] == ')') {
                    string next = cur.substr(0, i) + cur.substr(i+1);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        aQueue.push(next);
                    }
                }
            }
        }

        return res;
    }

    bool isValid(const string &s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') ++cnt;
            else if (c == ')') {
                if (--cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
};

int main() {
    return 0;
}
