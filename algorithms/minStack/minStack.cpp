/**
 *
 * Sean
 * 2016-08-24
 *
 * https://leetcode.com/problems/min-stack/
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> values;
    vector<int> minIndexes;
    int curPos;
    /** initialize your data structure here. */
    MinStack(): curPos(0) {
    }

    void push(int x) {
        if (values.empty()) {
            values.push_back(x);
            minIndexes.push_back(0);
            curPos = 1;
        } else {
            values.push_back(x);
            if (x < this->getMin()) {
                minIndexes.push_back(curPos);
            } else {
                minIndexes.push_back(minIndexes.back());
            }
            ++curPos;
        }
    }

    void pop() {
        if (!values.empty()) {
            values.pop_back();
            minIndexes.pop_back();
            --curPos;
        }
    }

    int top() {
        return values.back();
    }

    int getMin() {
        return values[minIndexes.back()];
    }
};

int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}
