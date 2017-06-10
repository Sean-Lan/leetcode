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
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// BFS with queue implementation.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> preCnts(numCourses, 0);
        vector<vector<int>> succs(numCourses);

        for (auto &aPair : prerequisites) {
            succs[aPair.second].push_back(aPair.first);
            ++ preCnts[aPair.first];
        }

        queue<int> aQueue;
        for (int i=0; i<numCourses; ++i) {
            if (preCnts[i] == 0) aQueue.push(i);
        }

        vector<int> res;

        int cur;
        while(!aQueue.empty()) {
            cur = aQueue.front();
            res.push_back(cur);
            aQueue.pop();
            for (auto next : succs[cur]) {
                if (--preCnts[next] == 0) aQueue.push(next);
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};

int main() {}
