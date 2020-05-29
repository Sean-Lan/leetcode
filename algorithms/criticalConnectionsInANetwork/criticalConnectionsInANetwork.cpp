/**
 *
 * Sean
 * 2020-05-29
 *
 * https://leetcode.com/problems/critical-connections-in-a-network/
 * There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections
 * forming a network where connections[i] = [a, b] represents a connection between servers a and b.
 * Any server can reach any other server directly or indirectly through the network.
 *
 * A critical connection is a connection that, if removed, will make some server unable to reach
 * some other server.
 *
 * Return all critical connections in the network in any order.
 *
 * Example 1:
 *
 * Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
 * Output: [[1,3]]
 * Explanation: [[3,1]] is also accepted.
 *
 * Constraints:
 *
 * 1 <= n <= 10^5
 * n-1 <= connections.length <= 10^5
 * connections[i][0] != connections[i][1]
 * There are no repeated connections.
 *
 */
#include <vector>
using namespace std;

// Reference: find AP https://www.hackerearth.com/zh/practice/notes/nj/
// basic idea is to find (u, v) which has no back edge.
class Solution {
  public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      vector<int> discovery(n);
      vector<int> low(n, INT_MAX);
      vector<vector<int>> adj(n);
      vector<vector<int>> criticalEdges;
      vector<bool> visited(n, false);
      int cnt = 0;

      for (auto& edge : connections) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }

      function<void(int, int)> dfs = [&] (int u, int parent) {
        discovery[u] = low[u] = ++cnt;
        visited[u] = true;

        for (int v : adj[u]) {
          if (!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > discovery[u]) { // there is no back-edge for the current child v
              criticalEdges.push_back({u, v});
            }
          } else if (v != parent) {
            low[u] = min(low[u], low[v]);
          }
        }
      };

      for (int i=0; i<n; ++i) {
        if (!visited[i]) {
          dfs(i, -1);
        }
      }

      return criticalEdges;
    }
};

int main() {
  return 0;
}
