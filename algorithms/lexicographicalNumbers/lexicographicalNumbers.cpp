/**
 *
 * Sean
 * 2016-09-28
 *
 * https://leetcode.com/problems/lexicographical-numbers/
 *
 * Given an integer n, return 1 - n in lexicographical order.
 *
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 *
 * Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
 *
 */
#include <vector>
#include <iostream>
using namespace std;

// DFS
// Reference to https://discuss.leetcode.com/topic/55377/simple-java-dfs-solution
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i=1; i<=9; ++i) {
            dfs(i, result, n);
        }
        return result;
    }
private:
    void dfs(int cur, vector<int> &result, int n) {
        if (cur > n) return;
        result.push_back(cur);
        for (int i=0; i<=9; ++i) {
            if (10*cur + i > n)
                break;
            dfs(10*cur + i, result, n);
        }
    }
};

int main() {}
