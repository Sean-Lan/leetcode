/**
 *
 * Sean
 * 2017-05-30
 *
 * https://leetcode.com/problems/implement-stack-using-queues/#/description
 *
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 *
 * Notes:
 *
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 *
 *
 */

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    // O(1)
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    // O(n)
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q.size();
        for (int i=1; i<n; ++i) {
            q.push(q.front());
            q.pop();
        }
        int e = q.front();
        q.pop();
        return e;
    }

    // O(n)
    /** Get the top element. */
    int top() {
       int n = q.size();
       for (int i=1; i<n; ++i) {
           q.push(q.front());
           q.pop();
       }
       int e = q.front();
       q.push(q.front());
       q.pop();
       return e;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main() {
    return 0;
}
