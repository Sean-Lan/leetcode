/**
 *
 * Sean
 * 2017-09-03
 *
 * https://leetcode.com/problems/graph-valid-tree/description/
 *
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
 *
 * For example:
 *
 * Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
 *
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 *
 * Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 *
 */
#include <iostream>
#include <queue>
using namespace std;

// number of edges equals to number of vertices - 1
// From any node of a Tree, you can visit all nodes => make sure no cycle
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n-1) return false;

        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        int cnt = 0;
        vector<bool> mark(n, false);
        mark[0] = true;
        queue<int> Q;
        Q.push(0);
        while (!Q.empty()) {
            ++cnt;
            int cur = Q.front();
            Q.pop();
            for (auto &next : adj[cur]) {
                if (!mark[next]) {
                    Q.push(next);
                    mark[next] = true;
                }
            }
        }
        return cnt == n;
    }
};

int main() {
    return 0;
}

