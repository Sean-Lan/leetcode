/**
 *
 * Sean
 * 2016-11-16
 *
 * Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
 *
 * Example:
 * Given a / b = 2.0, b / c = 3.0.
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 * The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
 *
 * According to the example above:
 *
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
 * The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
 *
 */
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

// treat the relationship as a graph, and run FW algorithm to calculate the distance.
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int cnt = 0;
        unordered_map<string, int> table;
        for (auto &aPair : equations) {
            if (table.count(aPair.first) == 0)
                table[aPair.first] = cnt++;
            if (table.count(aPair.second) == 0)
                table[aPair.second] = cnt++;
        }

        vector<vector<double>> d(cnt, vector<double>(cnt, 0));
        for (int i=0; i<cnt; ++i)
            d[i][i] = 1.0;

        double ratio;
        int x, y;
        for (int i=0; i<equations.size(); ++i) {
            ratio = values[i];
            x = table[equations[i].first];
            y = table[equations[i].second];
            d[x][y] = ratio;
            d[y][x] = 1/ratio;
        }

        for (int k = 0; k<cnt; ++k)
            for (int i=0; i<cnt; ++i)
                for (int j=0; j<cnt; ++j) {
                    if (d[i][k] && d[k][j])
                        d[i][j] = d[i][k] * d[k][j];
                }

        vector<double> res;
        for (auto &aPair : queries) {
            if (table.count(aPair.first) == 0 || table.count(aPair.second) == 0 ||
                d[table[aPair.first]][table[aPair.second]] == 0)
                res.push_back(-1.0);
            else
                res.push_back(d[table[aPair.first]][table[aPair.second]]);
        }
        return res;
    }
};

typedef vector<pair<string, string>> vss;
int main() {
    Solution solution;
    vss equations = { { "a","b" },{ "e","f" },{ "b","e" } };
    vector<double> values = { 3.4,1.4,2.3 };
    vss queries = { { "b","a" },{ "a","f" },{ "f","f" },{ "e","e" },{ "c","c" },{ "a","c" },{ "f","e" } };
    auto res = solution.calcEquation(equations, values, queries);
    for (auto &d : res) cout << d << endl;
    return 0;
}
