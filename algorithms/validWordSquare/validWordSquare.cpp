/**
 *
 * Sean
 * 2017-07-16
 *
 * https://leetcode.com/problems/valid-word-square/#/description
 *
 * Given a sequence of words, check whether it forms a valid word square.
 *
 * A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
 *
 * Note:
 * The number of words given is at least 1 and does not exceed 500.
 * Word length will be at least 1 and does not exceed 500.
 * Each word contains only lowercase English alphabet a-z.
 * Example 1:
 *
 * Input:
 * [
 *   "abcd",
 *   "bnrt",
 *   "crmy",
 *   "dtye"
 * ]
 *
 * Output:
 * true
 *
 * Explanation:
 * The first row and first column both read "abcd".
 * The second row and second column both read "bnrt".
 * The third row and third column both read "crmy".
 * The fourth row and fourth column both read "dtye".
 *
 * Therefore, it is a valid word square.
 * Example 2:
 *
 * Input:
 * [
 *   "abcd",
 *   "bnrt",
 *   "crm",
 *   "dt"
 * ]
 *
 * Output:
 * true
 *
 * Explanation:
 * The first row and first column both read "abcd".
 * The second row and second column both read "bnrt".
 * The third row and third column both read "crm".
 * The fourth row and fourth column both read "dt".
 *
 * Therefore, it is a valid word square.
 * Example 3:
 *
 * Input:
 * [
 *   "ball",
 *   "area",
 *   "read",
 *   "lady"
 * ]
 *
 * Output:
 * false
 *
 * Explanation:
 * The third row reads "read" while the third column reads "lead".
 *
 * Therefore, it is NOT a valid word square.
 *
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        // the length of words must be decreasing
        int m = words.size();
        if (m == 1) return words[0].size() == 1;

        int n = words[0].size();
        if (m !=n) return false;

        for (int i=0; i<m-1; ++i) {
            if (words[i].size() < words[i+1].size()) return false;
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<words[i].size(); ++j) {
                // corresponding letter must exist and equal
                if (words[j].size() < i+1 || words[i][j] != words[j][i]) return false;
            }
        }
        return true;

    }
};

int main() {
    return 0;
}
