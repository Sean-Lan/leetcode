#include <iostream>
/**
 *
 * Sean
 * 2016-03-29
 *
 * https://leetcode.com/problems/climbing-stairs/
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 */
#include <vector>
using namespace std;

vector<int> ways = {1,1};

// DP, using ways to catche the intermediate results.
class Solution {
    public:
        int climbStairs(int n) {
            while (ways.size()<=n) {
                ways.push_back(ways[ways.size()-1]+ways[ways.size()-2]);
            }
            return ways[n];
        }
};

int main() {
    Solution solution;
    cout << solution.climbStairs(2) << endl;
    cout << solution.climbStairs(3) << endl;
}
