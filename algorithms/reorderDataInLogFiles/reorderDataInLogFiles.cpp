/**
 *
 * Sean
 * 2020-06-07
 *
 * https://leetcode.com/problems/reorder-data-in-log-files/
 *
 * You have an array of logs.  Each log is a space delimited string of words.
 *
 * For each log, the first word in each log is an alphanumeric identifier.  Then, either:
 *
 * Each word after the identifier will consist only of lowercase letters, or;
 * Each word after the identifier will consist only of digits.
 * We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each
 * log has at least one word after its identifier.
 *
 * Reorder the logs so that all of the letter-logs come before any digit-log. The letter-logs are
 * ordered lexicographically ignoring identifier, with the identifier used in case of ties.
 * The digit-logs should be put in their original order.
 *
 * Return the final order of the logs.
 *
 * Example 1:
 *
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 *
 * Constraints:
 *
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the identifier.
 *
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto it = stable_partition(logs.begin(), logs.end(), [](const string& log) {
            return islower(log.back());
        });
        sort(logs.begin(), it, [](const string& log1, const string& log2) {
            int i = log1.find_first_of(' ');
            int j = log2.find_first_of(' ');
            string logPart1 = log1.substr(i);
            string logPart2 = log2.substr(j);
            if (logPart1 != logPart2) return logPart1 < logPart2;
            return log1.substr(0, i) < log2.substr(0, j);
        });
        return logs;
    }
};

int main() {
  return 0;
}
