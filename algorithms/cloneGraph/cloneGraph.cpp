/**
 *
 * Sean
 * 2016-03-20
 *
 * https://leetcode.com/problems/clone-graph/
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
 *      1
 *     / \
 *    /   \
 *   0 --- 2
 *        / \
 *        \_/
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// use a hash table to store the map from orginal node to copied node.
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> orginToNew;
        queue<UndirectedGraphNode *> nodeQueue;
        nodeQueue.push(node);
        UndirectedGraphNode *pOld, *pNew;
        while (!nodeQueue.empty()) {
            pOld = nodeQueue.front();
            nodeQueue.pop();
            pNew = new UndirectedGraphNode(pOld->label);
            orginToNew[pOld] = pNew;
            for (auto &p : pOld->neighbors)
                if (orginToNew.find(p)==orginToNew.end())
                    nodeQueue.push(p);
        }

        for (auto &aPair : orginToNew) {
            pOld = aPair.first;
            pNew = aPair.second;
            for (auto &p : pOld->neighbors)
                pNew->neighbors.push_back(orginToNew[p]);
        }

        return orginToNew[node];
    }
};

int main() {
    UndirectedGraphNode *_one = new UndirectedGraphNode(-1);
    UndirectedGraphNode *one = new UndirectedGraphNode(1);
    _one->neighbors.push_back(one);
    Solution solution;
    solution.cloneGraph(_one);
}
