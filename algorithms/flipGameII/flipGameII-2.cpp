/**
 *
 * Sean
 * 2016-11-28
 *
 * https://leetcode.com/problems/flip-game-ii/
 *
 * You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 *
 * Write a function to determine if the starting player can guarantee a win.
 *
 * For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".
 *
 * Follow up:
 * Derive your algorithm's runtime complexity.
 *
 */
#include <iostream>
#include <unordered_map>
using namespace std;

// DP O(2^n)
class Solution {
    unordered_map<string, bool> table;
    string s;
    int len;
    bool canWin() {
        if (table.count(s)) return table[s];
        bool win = false;
        for (int i=0; i<len-1; ++i) {
            if (s[i] == '+' && s[i] == s[i+1]) {
                s[i] = s[i+1] = '-';
                win = !canWin();
                s[i] = s[i+1] = '+';
                if (win) break;
            }
        }
        table[s] = win;
        return win;
    }
public:
    bool canWin(string s) {
        if (s.empty()) return false;
        this->s = s;
        len = s.size();
        return canWin();
    }
};

int main() {
    return 0;
}
