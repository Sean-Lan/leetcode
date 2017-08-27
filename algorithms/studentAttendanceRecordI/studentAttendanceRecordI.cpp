/**
 *
 * Sean
 * 2017-08-27
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * You are given a string representing an attendance record for a student. The record only contains the following three characters:
 *
 * 'A' : Absent.
 * 'L' : Late.
 * 'P' : Present.
 * A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his attendance record.
 *
 * Example 1:
 * Input: "PPALLP"
 * Output: True
 *
 * Example 2:
 * Input: "PPALLL"
 * Output: False
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        bool rewarded = true;
        bool absent = false;

        int n = s.size();
        for (int i=0; i<n; ++i) {
            if (s[i] == 'A') {
                if (absent) {
                    rewarded = false;
                    break;
                } else {
                    absent = true;
                }
            } else if (s[i] == 'L') {
                if (i > 1 && s[i-1] == 'L' && s[i-2] == 'L') {
                    rewarded = false;
                    break;
                }
            }
        }
        return rewarded;
    }
};

int main() {
    return 0;
}
