/**
 *
 * Sean
 * 2016-12-16
 *
 * https://leetcode.com/problems/walls-and-gates/
 *
 * You are given a m x n 2D grid initialized with these three possible values.
 *
 * -1 - A wall or an obstacle.
 *  0 - A gate.
 *  INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
 *  Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
 *
 *  For example, given the 2D grid:
 *  INF  -1  0  INF
 *  INF INF INF  -1
 *  INF  -1 INF  -1
 *    0  -1 INF INF
 *    After running your function, the 2D grid should be:
 *      3  -1   0   1
 *      2   2   1  -1
 *      1  -1   2  -1
 *      0  -1   3   4
 *
 */
#include <vector>
#include <queue>
using namespace std;

static const int DIRECTIONS[4][2] = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

// BFS
class Solution {
    public:
	void wallsAndGates(vector<vector<int>>& rooms) {
	    if (rooms.empty() || rooms[0].empty()) return;
	    queue<pair<int, int>> aQueue;
	    int m = rooms.size();
	    int n = rooms[0].size();
	    for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
		    if (rooms[i][j] == 0) aQueue.push({i, j});
		}
	    }

	    while (!aQueue.empty()) {
		auto cur = aQueue.front();
		aQueue.pop();
		int d = rooms[cur.first][cur.second];
		int nextX, nextY;
		for (auto &direction : DIRECTIONS) {
		    nextX = cur.first+direction[0];
		    nextY = cur.second+direction[1];
		    if (nextX>=0 && nextX<m && nextY>=0 && nextY<n &&
			    rooms[nextX][nextY]>d+1) {
			rooms[nextX][nextY] = d+1;
			aQueue.push({nextX, nextY});
		    }
		}
	    }
	}
};

int main() {
    return 0;
}
