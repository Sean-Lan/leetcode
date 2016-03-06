#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void printTmpResult(string result) {
    for (auto &c : result) c+='0';
    reverse(result.begin(), result.end());
    cout << "tmp: " << result << endl;
}

class Solution {
    public:
        string add(string num1, string num2) {
            string result;
            int len1 = num1.size();
            int len2 = num2.size();
            int cnt = 0, tmpSum = 0;
            int i=0;
            for (i=0; i<len1&&i<len2; ++i) {
                tmpSum = cnt+num1[i]+num2[i];
                result.push_back(tmpSum%10);
                cnt = tmpSum/10;
            }

            for (int j=i; j<len1; ++j) {
                tmpSum = cnt+num1[j];
                result.push_back(tmpSum%10);
                cnt = tmpSum/10;
            }
            
            for (int j=i; j<len2; ++j) {
                tmpSum = cnt+num2[j];
                result.push_back(tmpSum%10);
                cnt = tmpSum/10;
            }

            if (cnt)
                result.push_back(1);
            return result;
        }

        string multiplyOneDigit(string num1, char oneDigit, int shiftCnt) {
            if (oneDigit == 0)
                return {0};
            string result;
            for (int i=0; i<shiftCnt; i++)
                result.push_back(0);
            int cnt = 0, tmp = 0;
            for (auto &c : num1) {
                tmp = cnt + c*oneDigit;
                result.push_back(tmp%10);
                cnt = tmp/10;
            }
            if (cnt) result.push_back(cnt);
            return result;
        }

    public:
        string multiply(string num1, string num2) {
            if (num1.empty() || num2.empty())
                return "";
            if (num1 == "0" || num2 == "0")
                return "0";
            // preprocessing
            for (auto &c : num1) c -= '0';
            for (auto &c : num2) c -= '0';
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());

            string result = {0};
            int shiftCnt = 0;
            for (auto &c : num1) {
                result = add(result, multiplyOneDigit(num2, c, shiftCnt));
                ++shiftCnt;
            }
            for (auto &c: result) c += '0';
            reverse(result.begin(), result.end());
            return result;
        }
};


int main() {
    Solution solution;
    string num1 = "408", num2 = "5";
    string result = solution.multiply(num1, num2);

    cout << result << endl;


}
