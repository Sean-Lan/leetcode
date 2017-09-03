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
#include <numeric>
#include <vector>
using namespace std;

// Union Find
// make sure no cycle occur
class Solution {
    vector<int> root;
    vector<int> rank;
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n-1) return false;
        root = vector<int>(n);
        rank = vector<int>(n, 0);
        iota(root.begin(), root.end(), 0);
        for (auto &e : edges) {
            int i = findRoot(e.first);
            int j = findRoot(e.second);
            if (i == j) return false;
            if (rank[i] < rank[j]) {
                root[j] = root[i];
            } else {
                root[i] = root[j];
                if (rank[i] == rank[j]) ++rank[j];
            }
        }
        return true;
    }



    int findRoot(int x) {
        if (root[x] == x) return x;
        return root[x] = findRoot(root[x]);
    }
};

int main() {
    return 0;
}
