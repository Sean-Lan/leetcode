/**
 *
 * Sean
 * 2016-11-27
 *
 * https://leetcode.com/problems/nested-list-weight-sum/
 *
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
 *
 * Example 2:
 * Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
 *
 */
#include <vector>
#include <queue>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// BFS with a queue.
class Solution {
    typedef vector<NestedInteger>::const_iterator It;
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<pair<It, int>> aQueue;
        int sum = 0;
        for (auto it=nestedList.begin(); it!=nestedList.end(); ++it) {
            if (it->isInteger()) sum += it->getInteger();
            else {
                aQueue.push({it, 2});
            }
        }

        while(!aQueue.empty()) {
            auto aPair = aQueue.front();
            aQueue.pop();
            int level = aPair.second;
            auto &aList = aPair.first->getList();
            for (auto _it=aList.begin(); _it!=aList.end(); ++_it) {
                if (_it->isInteger()) sum += _it->getInteger()*level;
                else aQueue.push({_it, level+1});
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}
