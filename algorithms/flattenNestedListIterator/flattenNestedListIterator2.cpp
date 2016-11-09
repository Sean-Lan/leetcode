/**
 *
 * Sean
 * 2016-11-09
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 *
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 *
 * Example 2:
 * Given the list [1,[4,[6]]],
 *
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6]
 *
 */
#include <stack>
#include <vector>
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

// reference from https://discuss.leetcode.com/topic/41870/real-iterator-in-python-java-c
class NestedIterator {
    typedef vector<NestedInteger>::const_iterator It;
    stack<It> begs;
    stack<It> ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begs.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        It it = begs.top();
        ++ begs.top();
        return it->getInteger();
    }

    bool hasNext() {
        while (!begs.empty()) {
            It cur = begs.top();
            if (cur == ends.top()) {
                begs.pop();
                ends.pop();
                continue;
            }
            if (cur->isInteger()) return true;
            ++begs.top();
            begs.push(cur->getList().begin());
            ends.push(cur->getList().end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() { return 0; }
