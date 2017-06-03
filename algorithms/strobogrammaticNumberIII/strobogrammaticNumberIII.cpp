#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> dp0 = {1, 3}; // dp0[i]: number of valid string with length i
vector<int> dp1 = {1, 3}; // dp1[i]: number of valid string with length i and without leading 0s.
char strobo[] = {'0', '1', '8'};
vector<string> pairs = {"00", "11", "69", "88", "96"};

class Solution {
    int getDp0(int length) {
        if (dp0.size() > length)
            return dp0[length];
        while (dp0.size() <= length) {
            dp0.push_back(dp0[dp0.size()-2] * 5);
        }
        return dp0[length];
    }
    int getDp1(int length) {
        if (dp1.size() > length) {
            return dp1[length];
        }
        while (dp1.size() <= length) {
            dp1.push_back(getDp0(dp1.size()-2)*4);
        }
        return dp1[length];
    }

    bool lessThan(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) return s1.size() < s2.size();
        return s1 < s2;
    }
    void getCntInRange(const string &low, const string &high, int left, int right, string &s, int &res) {
        if (left > right) {
            if (lessThan(s, low) || lessThan(high, s)) return;
            if (s.size() > 1 && s[0] == '0') return; // number (length>1) with leading 0s is invalid
            ++ res;
            return;
        } else if (left == right) {
            for (auto c : strobo) {
                s[left] = c;
                getCntInRange(low, high, left+1, right-1, s, res);
            }
            return;
        }

        for (auto &aPair : pairs) {
            s[left] = aPair[0];
            s[right] = aPair[1];
            getCntInRange(low, high, left+1, right-1, s, res);
        }
    }
public:
    int strobogrammaticInRange(string low, string high) {
        int m = low.size();
        int n = high.size();
        int res = 0;
        // length between m & n can be caculated though dp
        for (int i=m+1; i<n; ++i) {
            res += getDp1(i);
        }

        // dfs
        if (m == n) {
            string s(n, '0');
            getCntInRange(low, high, 0, n-1, s, res);
        } else {
            string s(m, '0');
            getCntInRange(low, high, 0, m-1, s, res);
            s = string(n, '0');
            getCntInRange(low, high, 0, n-1, s, res);
        }
        return res;
    }
};

int main() {
    return 0;
}
