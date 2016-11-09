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

class NestedIterator {
    vector<int> result;
    int pos = 0;
    void pushNested(const NestedInteger &nested) {
        if (nested.isInteger()) {
            result.push_back(nested.getInteger());
        } else {
            for (auto &inner : nested.getList()) {
                pushNested(inner);
            }
        }
    }
public:
    // flatten it first.
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto &nested : nestedList) {
            pushNested(nested);
        }
    }

    int next() {
        return result[pos++];
    }

    bool hasNext() {
        return pos < result.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() { return 0; }
