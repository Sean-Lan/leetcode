/**
 *
 * Sean
 * 2016-10-19
 *
 * https://leetcode.com/problems/reconstruct-original-digits-from-english/
 *
 * Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
 *
 * Note:
 * Input contains only lowercase English letters.
 * Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
 * Input length is less than 50,000.
 *
 * Example 1:
 *  Input: "owoztneoer"
 *  Output: "012"
 *
 * Example 2:
 *  Input: "fviefuro"
 *  Output: "45"
 *
 */
#include <string>
#include <iostream>
using namespace std;

// reference from https://discuss.leetcode.com/topic/63386/one-pass-o-n-java-solution-simple-and-clear
// O(n)
// Basic idea is to count the times each number occurs.
class Solution {
public:
    string originalDigits(string s) {
        int counts[10] = {0};
        for (auto c : s) {
            if (c == 'z') ++counts[0];
            else if (c == 'w') ++counts[2];
            else if (c == 'u') ++counts[4];
            else if (c == 'x') ++counts[6];
            else if (c == 'g') ++counts[8];

            else if (c == 'f') ++counts[5]; // need - counts[4]
            else if (c == 'o') ++counts[1]; // need - counts[0] - counts[2] - counts[4]
            else if (c == 'h') ++counts[3]; // need - counts[8]
            else if (c == 's') ++counts[7]; // need - counts[6]
            else if (c == 'i') ++counts[9]; // need - (counts[5] + counts[6] + counts[8])
        }

        counts[5] -= counts[4];
        counts[1] = counts[1] - counts[0] - counts[2] - counts[4];
        counts[3] -= counts[8];
        counts[7] -= counts[6];
        counts[9] = counts[9] - counts[5] - counts[6] - counts[8];
        string res;
        for (int i=0; i<10; ++i) {
            for (int j=0; j<counts[i]; ++j)
                res.push_back('0'+i);
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.originalDigits("owoztneoer") << endl;
    cout << solution.originalDigits("fviefuro") << endl;
    cout << solution.originalDigits("zeroonetwothreefourfivesixseveneightnine") << endl;
    return 0;
}
