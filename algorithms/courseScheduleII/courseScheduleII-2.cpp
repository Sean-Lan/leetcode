/**
 *
 * Sean
 * 2016-10-05
 *
 * https://leetcode.com/problems/course-schedule-ii/
 *
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 *
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// DFS
class Solution {
    const static int WHITE;
    const static int GRAY;
    const static int BLACK;
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjancents(numCourses);
        vector<int> mark(numCourses, WHITE);
        vector<int> result;
        for (auto &aPair : prerequisites) {
            // adjancents[i] is all the courses which i dependents on
            adjancents[aPair.first].push_back(aPair.second);
        }
        for (int i=0; i<numCourses; ++i) {
            if (mark[i] == WHITE && !dfsVisit(i, adjancents, mark, result)) {
                return vector<int>();
            }
        }
        return result;
    }

    bool dfsVisit(int cur, vector<vector<int>> &adjancents, vector<int> &mark, vector<int> &result) {
        mark[cur] = GRAY;
        for (auto &neighbour : adjancents[cur])
            if (mark[neighbour] == GRAY ||
                (mark[neighbour] == WHITE && !dfsVisit(neighbour, adjancents, mark, result)))
                return false;
        mark[cur] = BLACK;
        result.push_back(cur);
        return true;
    }
};

const int Solution::WHITE = 0;
const int Solution::GRAY = 1;
const int Solution::BLACK = 2;

int main() {
    Solution solution;
    vector<pair<int, int>> prerequisites = {{1, 0}};
    auto result = solution.findOrder(2, prerequisites);
    for (auto &i : result)
        cout << i << " ";
    cout << endl;
}
