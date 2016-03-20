/**
 *
 * Sean
 * 2016-03-20
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 */
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {
    }
};

// use a hash map to store the map from orginal node to the copied one.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> originToNew;
        RandomListNode *fakeHead = new RandomListNode(0);
        RandomListNode *pNew = fakeHead;
        RandomListNode *p = head;
        while (p) {
            pNew->next = new RandomListNode(p->label);
            originToNew[p] = pNew->next;
            p = p->next;
            pNew = pNew->next;
        }

        p = head;
        pNew = fakeHead;
        while (p) {
            if (p->random)
                pNew->next->random = originToNew[p->random];
            p = p->next;
            pNew = pNew->next;
        }
        pNew = fakeHead->next;
        delete fakeHead;
        return pNew;
    }
};

int main() {}
