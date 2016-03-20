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
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// use a hash table to store the each node's position from the head.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        int cnt = 0;
        unordered_map<RandomListNode*, int> positionFromHead;
        RandomListNode *p = head;
        while (p) {
            positionFromHead[p] = cnt++;
            p = p->next;
        }

        vector<RandomListNode*> copied;
        p = head;
        RandomListNode *pNew = new RandomListNode(0);
        RandomListNode *fakeHead = pNew;
        RandomListNode *tmp;
        while (p) {
            tmp = new RandomListNode(p->label);
            copied.push_back(tmp);
            pNew->next = tmp;
            pNew = tmp;
            p = p->next;
        }
        delete fakeHead;

        p = head;
        pNew = copied[0];
        while (p) {
            if (p->random)
                pNew->random = copied[positionFromHead[p->random]];
            pNew = pNew->next;
            p = p->next;
        }
        return copied[0];
    }
};

int main() {}
