/**
 *
 * Sean
 * 2017-06-21
 *
 * https://leetcode.com/problems/additive-number/#/description
 *
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 *
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 *
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 *
 */
#include <iostream>
#include <string>
using namespace std;

// big number addition
class Solution {
    string bigAdd(const string &num1, const string &num2) {
        string res;
        int i = num1.size()-1;
        int j = num2.size()-1;
        int cnt = 0;
        int tmp;

        while (i>=0 && j>=0) {
            tmp = num1[i] + num2[j] -'0' - '0' + cnt;
            cnt = tmp/10;
            tmp = tmp%10;
            res.push_back(tmp+'0');
            --i;
            --j;
        }

        while (i>=0) {
            tmp = num1[i] - '0' + cnt;
            cnt = tmp/10;
            tmp = tmp%10;
            res.push_back(tmp+'0');
            --i;
        }

        while (j>=0) {
            tmp = num2[j] - '0' + cnt;
            cnt = tmp/10;
            tmp = tmp%10;
            res.push_back(tmp+'0');
            --j;
        }

        if (cnt) {
            res.push_back('1');
        }
        return string(res.rbegin(), res.rend());
    }

    bool helper(const string&num, int i, int len1, int j, int len2) {
        string num1 = num.substr(i, len1);
        string num2 = num.substr(j, len2);
        string num3 = bigAdd(num1, num2);
        int k = j+len2;
        int len3 = num3.size();
        if (k + len3 > num.size()) return false;
        for (int l=0; l<len3; ++l) {
            if (num[k+l] != num3[l]) return false;
        }
        if (k + len3 == num.size()) return true;
        return helper(num, j, len2, k, len3);
    }

public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        int n = num.size();
        for (int len1=1; len1<=n/2; ++len1) {
            if (num[0] == '0' && len1 > 1) continue;
            // do proper pruning
            for (int len2=1; len1+len2+max(len1,len2) <= n; ++len2) {
                if(num[len1] == '0' & len2 > 1) continue;
                // cout << "! " << len1 << " " << len2 << endl;
                if (helper(num, 0, len1, len1, len2)) return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
