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
#include <list>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

typedef list<int>::iterator IT;

// use a map as an index
// pop, popMax and peekMax are O(logN)
// top is O(1)
class MaxStack {
  private:
    list<int> aList;
    map<int, vector<IT>, std::greater<int>> aMap;
  public:
    /** initialize your data structure here. */
    MaxStack() {
    }

    void push(int x) {
      aList.push_back(x);
      IT it = prev(aList.end());
      if (aMap.find(x) != aMap.end()) {
        vector<IT>& vit = aMap[x];
        vit.push_back(it);
      } else {
        aMap[x] = {it};
      }
    }

    int pop() {
      int x = aList.back();
      vector<IT> &vit = aMap[x];
      vit.pop_back();
      if (vit.empty()) aMap.erase(x);

      aList.pop_back();
      return x;
    }

    int top() {
      return aList.back();
    }

    int peekMax() {
      return aMap.begin()->first;
    }

    int popMax() {
      auto p = aMap.begin();
      int x  = p->first;
      vector<IT> vit = aMap.begin()->second;
      IT it = vit.back();
      aList.erase(it);
      vit.pop_back();
      if (vit.empty()) aMap.erase(p);
      return x;
    }
};

int main() {
  return 0;
}
