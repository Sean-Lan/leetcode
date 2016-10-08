/**
 *
 * Sean
 * 2016-10-08
 *
 * https://leetcode.com/problems/binary-watch/
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
 *
 * Each LED represents a zero or one, with the least significant bit on the right.
 *
 * hour:   0 0 1 1
 * minute: 0 1 1 0 0 1
 *
 * For example, the above binary watch reads "3:25".
 *
 * Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
 *
 * Example:
 *
 * Input: n = 1
 * Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 * Note:
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// DFS
// Use an integer as the possible binary representation
class Solution {
private:
    void dfs(int index, int cnt, int num, int x, vector<int> &binaries) {
        if (index == 10) {
            binaries.push_back(x);
            return;
        }
        if (cnt < num) { // could add more 1
            dfs(index+1, cnt+1, num, x|(1<<index), binaries);
        }
        if (10 - index > num - cnt) { // could add more 0
            dfs(index+1, cnt, num, x, binaries);
        }
    }

    string convertTime(int x) {
        int hour = x & 0xf;
        int minute = x >> 4;
        if (hour > 11 || minute > 59) // out of range
            return "";
        string s_hour = to_string(hour);
        string s_minute = to_string(minute);
        if (s_minute.size() == 1)
            s_minute = '0' + s_minute;
        return s_hour + ':' + s_minute;
    }

public:
    vector<string> readBinaryWatch(int num) {
        vector<int> binaries;
        dfs(0, 0, num, 0, binaries);
        vector<string> res;
        for (auto &x : binaries) {
            string s_time = convertTime(x);
            if (!s_time.empty())
                res.push_back(s_time);
        }
        return res;
    }

};

int main() {
    Solution solution;
    auto res = solution.readBinaryWatch(2);
    for (auto &x : res)
        cout << x << endl;
    return 0;
}
