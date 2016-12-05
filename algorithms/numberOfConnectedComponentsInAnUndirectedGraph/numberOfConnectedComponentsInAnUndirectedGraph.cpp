/**
 *
 * Sean
 * 2016-12-05
 *
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
 *
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
 * 
 * Example 1:
 *      0          3
 *      |          |
 *      1 --- 2    4
 * Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
 * 
 * Example 2:
 *      0           4
 *      |           |
 *      1 --- 2 --- 3
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 * 
 * Note:
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 *
 */
#include <numeric>
#include <vector>
using namespace std;

class Unions {
private:
    vector<int> ranks;
public:
    vector<int> roots;
    Unions(int size) {
        roots = vector<int>(size);
        ranks = vector<int>(size, 0);
        iota(roots.begin(), roots.end(), 0);
    }
    
    int findRoot(int i) {
        if (roots[i] != i)
            roots[i] = findRoot(roots[i]);
        return roots[i];
    }
    
    int unionAll(int i, int j) {
        int root1 = findRoot(i);
        int root2 = findRoot(j);
        if (ranks[root1] > ranks[root2]) {
            return roots[root2] = root1;
        } else {
            if (ranks[root1] == ranks[root2]) ++ranks[root2];
            return roots[root1] = root2;
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        Unions unions = Unions(n);
        for (auto &aPair : edges) {
            unions.unionAll(aPair.first, aPair.second);
        }
        int cnt = 0;
        for (int i=0; i<n; ++i) {
            if (unions.roots[i] == i) ++cnt;
        }
        return cnt;
    }
};

int main() {
    return 0;
}
