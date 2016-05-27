/**
 *
 * Sean
 * 2016-05-27
 *
 * https://leetcode.com/problems/restore-ip-addresses/
 *
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 */
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        // iterative solution.
        vector<string> restoreIpAddresses(string s) {
            int size = s.size();
            if (size < 4) return {};
            string s1, s2, s3, s4;
            vector<string> results;
            int maxK;
            for (int i = 0; i<3; ++i) {
                s1 = s.substr(0, i+1);
                if (!isValid(s1)) break;;
                for (int j = size-1; j>=size-3; --j) {
                    s4= s.substr(j);
                    if (!isValid(s4)) continue;
                    maxK = min(i+3, j-2);
                    for (int k = i+1; k<=maxK; ++k) {
                        s2 = s.substr(i+1, k-i);
                        if (!isValid(s2)) break;
                        s3 = s.substr(k+1, j-k-1);
                        if (isValid(s3))
                            results.push_back(s1+"."+s2+"."+s3+"."+s4);
                    }
                }
            }
            return results;
        }

        // dfs solution
        vector<string> restoreIpAddresses2(string s) {
            vector<string> results;
            vector<string> currentResult;
            dfs(s, 0, currentResult, results);
            return results;
        }

        void dfs(string &s, int pos, vector<string> &currentResult, vector<string> &results) {
            int size = s.size();
            if (pos == size && currentResult.size() == 4) {
                results.push_back(std::accumulate(currentResult.begin(), currentResult.end(), string{},
                            [](const string &s1, const string &s2) {
                                return s1.empty()? s2 : (s1+"."+s2);
                            }));
                return;
            }
            if (currentResult.size() == 4 || pos == size)
                return;
            for (int i=1; i<=3&&pos+i-1<size; ++i) {
                string cur = s.substr(pos, i);
                if (isValid(cur)) {
                    currentResult.push_back(cur);
                    dfs(s, pos+i, currentResult, results);
                    currentResult.pop_back();
                } else {
                    break;
                }
            }
        }
        

        bool isValid(const string& part) {
            if (part.empty() || part.size() > 4) return false;
            if (part.size() > 1 && part[0] == '0')
                return false;
            if (std::stoi(part) > 255)
                return false;
            return true;
        }
};

void printResult(const vector<string> &results) {
    for (auto &s : results) {
        cout << s << endl;
    }
}

int main() {
    Solution solution;
    printResult(solution.restoreIpAddresses2("1111"));
}
