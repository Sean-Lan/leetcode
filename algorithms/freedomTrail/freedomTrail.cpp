/**
 *
 * Sean
 * 2017-09-05
 *
 * https://leetcode.com/problems/freedom-trail/description/
 *
 * In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.
 *
 * Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
 *
 * Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.
 * At the stage of rotating the ring to spell the key character key[i]:
 * You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
 * If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
 *
 * Example:
 * Input: ring = "godding", key = "gd"
 * Output: 4
 *
 * Explanation:
 *  For the first key character 'g', since it is already in place, we just need 1 step to spell this character.
 *  For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
 *  Also, we need 1 more step for spelling.
 *  So the final output is 4.
 *
 * Note:
 *  1. Length of both ring and key will be in range 1 to 100.
 *  2. There are only lowercase letters in both strings and might be some duplcate characters in both strings.
 *  3. It's guaranteed that string key could always be spelled by rotating the string ring.
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// typical DP
class Solution {
    vector<vector<int>> cache;
    string ring, key;
    int m, n;
    int sovle(int s, int e) {
        if (e == n) return 0;
        if (cache[s][e] != -1) return cache[s][e];
        char target = key[e];
        int value = INT_MAX;
        for (int i=0; i<m; ++i) {
            if (ring[i] == target) {
                value = min(value, min((s-i+m)%m, (i-s+m)%m)+1+sovle(i, e+1));
            }
        }
        return cache[s][e] = value;
    }
public:
    int findRotateSteps(string ring, string key) {
        this->ring = ring;
        this->key = key;
        this->m = ring.size();
        this->n = key.size();
        cache = vector<vector<int>>(m, vector<int>(n, -1));
        return sovle(0, 0);
    }
};

int main() {
    return 0;
}
