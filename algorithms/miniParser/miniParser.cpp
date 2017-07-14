/**
 *
 * Sean
 * 2017-07-14
 *
 * https://leetcode.com/problems/mini-parser/#/description
 *
 * Given a nested list of integers represented as a string, implement a parser to deserialize it.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Note: You may assume that the string is well-formed:
 *
 * String is non-empty.
 * String does not contain white spaces.
 * String contains only digits 0-9, [, - ,, ].
 * Example 1:
 *
 * Given s = "324",
 *
 * You should return a NestedInteger object which contains a single integer 324.
 * Example 2:
 *
 * Given s = "[123,[456,[789]]]",
 *
 * Return a NestedInteger object containing a nested list with 2 elements:
 *
 * 1. An integer containing value 123.
 * 2. A nested list containing two elements:
 *     i.  An integer containing value 456.
 *     ii. A nested list with one element:
 *          a. An integer containing value 789.
 *
 */
#include <iostream>
#include <vector>
#include <stack>
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

// One pass solution
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            int i = atoi(s.c_str());
            return NestedInteger(i);
        }

        int n = s.size();
        stack<NestedInteger *> aStack;
        char c;
        int num = 0;
        bool parsingNumber = false;
        bool positive = true;
        NestedInteger ni;
        aStack.push(&ni);
        for (int i=1; i<n; ++i) {
            c = s[i];
            if (c == '[') {
                // need to use new, otherwise its a temporty variable and will gets destroyed
                // in next round of loop
                NestedInteger *p = new NestedInteger();
                aStack.push(p);
            } else if (c == ']') {
                if (parsingNumber) {
                    aStack.top()->add(NestedInteger(positive ? num : -num));
                    parsingNumber = false;
                    positive = true;
                    num = 0;
                }
                auto p = aStack.top();
                aStack.pop();
                // needs to add the NestedInteger after it gets poped out
                // since in C++ `void add(const NestedInteger &ni);` will copy the value instead of a reference
                if (!aStack.empty())
                    aStack.top()->add(*p);
            } else if (c == ',') {
                if (parsingNumber) {
                    aStack.top()->add(NestedInteger(positive ? num : -num));
                    parsingNumber = false;
                    positive = true;
                    num = 0;
                }
            } else if (c == '-') {
                positive = false;
                parsingNumber = true;
            } else {
                parsingNumber = true;
                num = num*10 + c-'0';
            }
        }
        return ni;
    }
};

int main() {
    return 0;
}
