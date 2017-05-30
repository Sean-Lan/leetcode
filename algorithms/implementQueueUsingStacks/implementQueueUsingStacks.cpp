/**
 *
 * Sean
 * 2017-05-30
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/#/description
 *
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 *
 * Notes:
 * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 *
 */
#include <stack>
#include <iostream>
using namespace std;

// amortized O(1) peek and pop, since the element will be pushed into s1 once, popped from s1 once,
// pushed into s2 once and popped from s2 once
class MyQueue {
    stack<int> s1, s2;
    void s1ToS2() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            s1ToS2();
        }
        int e = s2.top();
        s2.pop();
        return e;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            s1ToS2();
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {
    return 0;
}
