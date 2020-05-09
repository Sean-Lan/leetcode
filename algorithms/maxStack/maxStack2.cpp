/**
 *
 * Sean
 * 2020-05-09
 *
 * https://leetcode.com/problems/max-stack/
 *
 * Design a max stack that supports push, pop, top, peekMax and popMax.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Remove the element on top of the stack and return it.
 * top() -- Get the element on the top.
 * peekMax() -- Retrieve the maximum element in the stack.
 * popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
 *
 * Example 1:
 * MaxStack stack = new MaxStack();
 * stack.push(5);
 * stack.push(1);
 * stack.push(5);
 * stack.top(); -> 5
 * stack.popMax(); -> 5
 * stack.top(); -> 1
 * stack.peekMax(); -> 5
 * stack.pop(); -> 1
 * stack.top(); -> 5
 *
 * Note:
 * -1e7 <= x <= 1e7
 * Number of operations won't exceed 10000.
 * The last four operations won't be called when stack is empty.
 *
 */
#include <iostream>
#include <stack>
using namespace std;

// use two stacks: one for elements, one for the max values
// push/pop/peekMax: O(1)
// popMax: O(n)
class MaxStack {
  private:
    stack<int> elems;
    stack<int> maxElems;
  public:
    /** initialize your data structure here. */
    MaxStack() {
    }

    void push(int x) {
      elems.push(x);
      if (maxElems.empty()) {
        maxElems.push(x);
      } else {
        maxElems.push(max(maxElems.top(), x));
      }
    }

    int pop() {
      int x = elems.top();
      elems.pop();
      maxElems.pop();
      return x;
    }

    int top() {
      return elems.top();
    }

    int peekMax() {
      return maxElems.top();
    }

    int popMax() {
      int x = maxElems.top();
      stack<int> tmp;
      while (top() != x) {
        tmp.push(pop());
      }
      pop();
      while (!tmp.empty()) {
        push(tmp.top());
        tmp.pop();
      }
      return x;
    }
};

int main() {
  return 0;
}
