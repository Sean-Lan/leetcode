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
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// use union find.
class Unions {
    private:
        unordered_map<string, string> roots;
        unordered_map<string, int> ranks;
        unordered_map<string, double> values;
        inline void init(const string &s) {
            roots[s] = s;
            ranks[s] = 0;
            values[s] = 1.0;
        }
    public:
        string findRoot(const string& s) {
            if (roots[s] != s) {
                string root = roots[s];
                roots[s] = findRoot(root);
                // update the value by the way.
                values[s] *= values[root];
            }
            return roots[s];
        }

        // ratio = s/t
        void unionAll(const string& s, const string& t, double ratio) {
            if (!roots.count(s)) init(s);
            if (!roots.count(t)) init(t);

            string rootS = findRoot(s);
            string rootT = findRoot(t);
            if (rootS == rootT) return;
            if (ranks[rootS] > ranks[rootT]) {
                roots[t] = rootS;
                // set the value
                values[t] = values[s] * 1/ratio;
            } else {
                roots[s] = rootT;
                values[s] = values[t] * ratio;
                if (ranks[rootS] == ranks[rootT])
                    ++ ranks[rootT];
            }
        }

        double getValue(const string& s) {
            return values[s];
        }

        bool has(const string& s) {
            return roots.count(s);
        }
};

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        Unions unions;
        int n = equations.size();
        for (int i=0; i<n; ++i) {
            string &s = equations[i].first;
            string &t = equations[i].second;
            double ratio = values[i];
            unions.unionAll(s, t, ratio);
        }

        vector<double> results;
        for (auto &aPair : queries) {
            string &s = aPair.first;
            string &t = aPair.second;
            if (!unions.has(s) || !unions.has(t)) {
                results.push_back(-1.0);
                continue;
            }
            string rootS = unions.findRoot(s);
            string rootT = unions.findRoot(t);
            if (rootS != rootT)
                results.push_back(-1.0);
            else {
                double valueS = unions.getValue(s);
                double valueT = unions.getValue(t);
                results.push_back(valueS/valueT);
            }
        }
        return results;
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
