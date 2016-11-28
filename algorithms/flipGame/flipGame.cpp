/**
 *
 * Sean
 * 2016-11-28
 *
 * https://leetcode.com/problems/flip-game/
 *
 * You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 *
 * Write a function to compute all possible states of the string after one valid move.
 *
 * For example, given s = "++++", after one move, it may become one of the following states:
 *
 * [
 *   "--++",
 *   "+--+",
 *   "++--"
 * ]
 *
 * If there is no valid move, return an empty list [].
 *
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        if (s.size() < 2) return {};
        vector<string> res;
        string cur;
        for (int i=0; i<s.size()-1; ++i) {
            cur = s;
            if (cur[i] == '+' && cur[i] == cur[i+1]) {
                cur[i] = cur[i+1] = '-';
                res.push_back(cur);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
