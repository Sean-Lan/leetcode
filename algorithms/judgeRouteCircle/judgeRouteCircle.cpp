/**
 *
 * Sean
 * 2017-08-27
 *
 * https://leetcode.com/problems/judge-route-circle/description/
 *
 * Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 *
 * The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 *
 * Example 1:
 * Input: "UD"
 * Output: true
 * Example 2:
 * Input: "LL"
 * Output: false
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (auto c : moves) {
            if (c == 'U') { --x; }
            else if (c == 'D') { ++x; }
            else if (c == 'L') { --y; }
            else { ++ y; }
        }
        return x == 0 && y == 0;
    }
};

int main() {
    return 0;
}
