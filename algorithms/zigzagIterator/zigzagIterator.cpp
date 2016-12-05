/**
 *
 * Sean
 * 2016-12-05
 *
 * https://leetcode.com/problems/zigzag-iterator/
 *
 * Given two 1d vectors, implement an iterator to return their elements alternately.
 *
 * For example, given two 1d vectors:
 *
 * v1 = [1, 2]
 * v2 = [3, 4, 5, 6]
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
 *
 * Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
 *
 * Clarification for the follow up question - Update (2015-09-18):
 * The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
 *
 * [1,2,3]
 * [4,5,6,7]
 * [8,9]
 *
 * It should return [1,4,8,2,5,9,3,6,7].
 *
 */
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

// use a linked list to store the pointer to a vector and next iterative index.
class ZigzagIterator {
    typedef list<pair<vector<int> *, int>> List;
    List::iterator kth;
    List vecs;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) vecs.push_back({&v1, 0});
        if (!v2.empty()) vecs.push_back({&v2, 0});
        kth = vecs.begin();
    }

    int next() {
        auto pVec = kth->first;
        auto &index = kth->second;
        auto nextIt = std::next(kth);
        int value = (*pVec)[index++];
        if (index == pVec->size()) {
            vecs.erase(kth);
        }
        kth = (nextIt == vecs.end()) ? vecs.begin() : nextIt;
        return value;
    }

    bool hasNext() {
        return !vecs.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {11,22,33};
    ZigzagIterator zit(v1, v2);
    while (zit.hasNext()) {
        cout << zit.next() << endl;
    }
    return 0;
}
