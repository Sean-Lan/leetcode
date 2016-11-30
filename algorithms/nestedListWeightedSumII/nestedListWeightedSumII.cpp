/**
 *
 * Sean
 * 2016-11-30
 *
 * https://leetcode.com/problems/nested-list-weight-sum-ii/
 *
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
 *
 * Example 2:
 * Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
 *
 */
#include <vector>
#include <queue>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// first use dfs to get height, the bfs to calculate result.
class Solution {
    typedef vector<NestedInteger>::const_iterator It;
    int getHeight(const vector<NestedInteger> &nestedList) {
        int height = 0;
        for (auto it=nestedList.begin(); it!=nestedList.end(); ++it) {
            if (!it->isInteger()) height = max(height, getHeight(it->getList()));
        }
        return height+1;
    }
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int height = getHeight(nestedList);
        int sum = 0;
        queue<pair<It, int>> aQueue;
        for (auto it=nestedList.begin(); it!=nestedList.end(); ++it) {
            if (it->isInteger()) sum += it->getInteger()*height;
            else aQueue.push({it, height-1});
        }
        It it;
        while (!aQueue.empty()) {
            auto& aPair = aQueue.front();
            it = aPair.first;
            height = aPair.second;
            aQueue.pop();
            for (auto _it = it->getList().begin(); _it!=it->getList().end(); ++_it) {
                if (_it->isInteger()) sum += _it->getInteger() * height;
                else aQueue.push({_it, height-1});
            }
        }
        return sum;
    }
};
