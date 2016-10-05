/**
 *
 * Sean
 * 2016-09-30
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
#include <queue>
#include <vector>
using namespace std;

// Topological sort with BFS
// Reference to https://en.wikipedia.org/wiki/Topological_sorting#Algorithms
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> count(numCourses, 0);
        vector<vector<int>> adjancent(numCourses);
        for (auto &aPair : prerequisites) {
            ++count[aPair.first];
            adjancent[aPair.second].push_back(aPair.first);
        }

        queue<int> courses;
        int cnt = 0;
        for (int i = 0; i<numCourses; ++i) {
            if (count[i] == 0) {
                courses.push(i);
                ++cnt;
            }
        }

        while (!courses.empty()) {
            int cur = courses.front();
            courses.pop();
            for (auto &next : adjancent[cur]) {
                --count[next];
                if (count[next] == 0) {
                    ++cnt;
                    courses.push(next);
                }
            }
        }
        return cnt == numCourses;
    }
};

int main() {}
