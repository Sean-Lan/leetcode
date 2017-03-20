/**
 *
 * Sean
 * 2017-03-20
 *
 * https://leetcode.com/problems/minimum-time-difference/
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
 *
 * Example 1:
 *   Input: ["23:59","00:00"]
 *   Output: 1
 *
 * Note:
 *   The number of time points in the given list is at least 2 and won't exceed 20000.
 *   The input time is legal and ranges from 00:00 to 23:59.
 *
 */
#include <vector>
#include <string>
using namespace std;

// sort and calculate diff
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        auto timeToInt = [](const string &t) {
            int h = stoi(t.substr(0,2));
            int m = stoi(t.substr(3,2));
            return h*60 + m;
        };
        sort(timePoints.begin(), timePoints.end());
        int minDiff = INT_MAX;
        int n = timePoints.size();
        auto timeDiff = [&timeToInt] (const string &t1, const string &t2) {
            return timeToInt(t2) - timeToInt(t1);
        };
        for (int i=0; i<n-1; ++i) {
            minDiff = min(minDiff, timeDiff(timePoints[i], timePoints[i+1]));
        }
        minDiff = min(minDiff, timeDiff(timePoints[n-1], timePoints[0]) + 60*24);
        return minDiff;
    }
};
