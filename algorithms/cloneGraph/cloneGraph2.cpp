/**
 *
 * Sean
 * 2017-09-03
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 *
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 *
 */
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// BFS
// use a hash table to store the mapping from label to the cloned node
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        unordered_map<int, UndirectedGraphNode *> table;
        table[node->label] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> Q;
        Q.push(node);

        while (!Q.empty()) {
            UndirectedGraphNode *p = Q.front();
            UndirectedGraphNode *cloned = table[p->label];
            Q.pop();
            for (auto &next : p->neighbors) {
                if (!table.count(next->label)) {
                    table[next->label] = new UndirectedGraphNode(next->label);
                    Q.push(next);
                }
                cloned->neighbors.push_back(table[next->label]);
            }
        }

        return table[node->label];
    }
};

int main() {
    return 0;
}
