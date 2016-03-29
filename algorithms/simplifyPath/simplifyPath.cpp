/**
 *
 * Sean
 * 2016-03-29
 *
 * https://leetcode.com/problems/simplify-path/
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 *     Did you consider the case where path = "/../"?
 *     In this case, you should return "/".
 *     Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 *     In this case, you should ignore redundant slashes and return "/home/foo".
 *
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Use stack
class Solution {
    public:
        string simplifyPath(string path) {
            // preprocess the path
            int i=0, len=0;
            // 1. remove the start slashes
            while (i<path.size() && path[i]=='/') ++i;
            // 2. remove redundant slashes
            bool flag = false;
            for (; i<path.size(); ++i) {
                if (path[i]=='/') {
                    if (flag) continue;
                    flag = true;
                    path[len++] = '/';
                } else {
                    flag = false;
                    path[len++] = path[i];
                }
            }

            // 3. put a slash at then end of path
            if (len==0 || path[len-1]!='/') path[len++] = '/';

            // put all the path parts into a stack
            stack<string> aStack;
            int start = 0;
            for (i=start; i<len; ++i) {
                if (path[i]=='/') {
                    aStack.push(path.substr(start, i-start));
                    start = i+1;
                }
            }

            // process the stack, remove all '.'s, all '..'s
            stack<string> processed;
            string tmp;
            int cnt;
            while (!aStack.empty()) {
                tmp = aStack.top();
                aStack.pop();
                if (tmp == "..") {
                    cnt = 1;
                    while (cnt && !aStack.empty()) {
                        tmp = aStack.top();
                        aStack.pop();
                        if (tmp == "..")
                            ++cnt;
                        else if (tmp == ".")
                            continue;
                        else
                            --cnt;
                    }
                    continue;
                }
                if (tmp==".") continue;
                processed.push(tmp);
            }

            // construct the final result
            string result;
            while (!processed.empty()) {
                result += '/';
                result += processed.top();
                processed.pop();
            }
            if (result.empty()) result += '/';
            return result;
        }
};

int main() {
    string path = "/a/./b/../../c/";
    Solution solution;
    cout << solution.simplifyPath(path) << endl;
    path = "/home/of/foo/../../bar/../../is/./here/.";
    cout << solution.simplifyPath(path) << endl;
}
