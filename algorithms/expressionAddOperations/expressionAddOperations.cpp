/**
 *
 * Sean
 * 2016-03-24
 *
 * https://leetcode.com/problems/expression-add-operators/
 *
 * Given a string that contains only digits 0-9 and a target value, return all possibilities to add
 * binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
 *
 * Examples:
 * "123", 6 -> ["1+2+3", "1*2*3"]
 * "232", 8 -> ["2*3+2", "2+3*2"]
 * "105", 5 -> ["1*0+5","10-5"]
 * "00", 0 -> ["0+0", "0-0", "0*0"]
 * "3456237490", 9191 -> []
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// DFS.
// save current number to `previousValue` to handle the '*' case.
// Careful about integer overflow.
class Solution {
    public:
        vector<string> addOperators(string num, int target) {
            if (num.empty()) return {};
            vector<string> results;
            helper(results, "", 0, 0, 0, num, target);
            return results;
        }

    private:
        void helper(vector<string> &results, string currentResult, int pos, long currentValue, long previousValue,
                const string &num, const int &target) {
            if (pos == num.size()) {
                if (currentValue == target)
                    results.push_back(currentResult);
                return;
            }

            for (int i=pos; i<num.size(); ++i) {
                // "0X" cannot show up.
                if (num[pos]=='0' && i>pos) break;
                string _str = num.substr(pos, i-pos+1);
                long _value = stol(_str);
                if (pos==0)
                    helper(results, currentResult+_str, i+1, _value, _value, num, target);
                else {
                    helper(results, currentResult+'+'+_str, i+1,
                            currentValue+_value, _value, num, target);
                    helper(results, currentResult+'-'+_str, i+1,
                            currentValue-_value,-_value, num, target);
                    helper(results, currentResult+'*'+_str, i+1,
                            currentValue-previousValue+previousValue*_value, previousValue*_value, num, target);
                }
            }
        }
};

void printResults(vector<string> &results) {
    for (auto s : results)
        cout << s << endl;
}

int main() {
    Solution solution;
    auto results = solution.addOperators("232", 8);
    cout << "232 8" << endl;
    printResults(results);
    cout << endl;

    results = solution.addOperators("00", 0);
    cout << "00 0" << endl;
    printResults(results);
    cout << endl;

    results = solution.addOperators("300", 90);
    cout << "300 90" << endl;
    printResults(results);
    cout << endl;
}
