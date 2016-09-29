/**
 *
 * Sean
 * 2016-09-29
 *
 * https://leetcode.com/problems/course-schedule/
 *
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 *
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 *
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 *
 */
#include <vector>
#include <utility>
using namespace std;

// DFS to check if there is a cycle.
class Solution {
    static const int WHITE;
    static const int GRAY;
    static const int BLACK;
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjacents(numCourses);
        for (auto &aPair : prerequisites) {
            adjacents[aPair.first].push_back(aPair.second);
        }
        vector<int> color(numCourses, WHITE);
        return dfs(adjacents, color);
    }

    bool dfs(vector<vector<int>> &adjacents, vector<int> &color) {
        for (int i=0; i<adjacents.size(); ++i) {
            if (color[i] == WHITE && !dfsVisit(i, adjacents, color))
                return false;
        }
        return true;
    }

    bool dfsVisit(int cur, vector<vector<int>> &adjacents, vector<int> &color) {
        color[cur] = GRAY;
        for (auto &neighbour : adjacents[cur]) {
            if (color[neighbour] == GRAY) return false;
            if (color[neighbour] == WHITE && !dfsVisit(neighbour, adjacents, color))
                return false;
        }
        color[cur] = BLACK;
        return true;
    }
};

const int Solution::WHITE = 0;
const int Solution::GRAY = 1;
const int Solution::BLACK = 2;

int main() {
    Solution solution;
    int numCourses = 2;
    vector<pair<int, int>> prerequisites = { {1, 0}, {0, 1}};
    solution.canFinish(numCourses, prerequisites);
    return 0;
}
