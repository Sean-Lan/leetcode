/**
 *
 * Sean
 * 2017-09-27
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 */
#include <unordered_map>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// One-pass solution with hash map
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        unordered_map<RandomListNode *, RandomListNode *> table;
        RandomListNode *p = head;

        while (p) {
            if (!table.count(p)) {
                table[p] = new RandomListNode(p->label);
            }
            if (p->random) {
                if (!table.count(p->random)) table[p->random] = new RandomListNode(p->random->label);
                table[p]->random = table[p->random];
            }
            if (p->next) {
                if(!table.count(p->next)) table[p->next] = new RandomListNode(p->next->label);
                table[p]->next = table[p->next];
            }
            p = p->next;
        }

        return table[head];
    }
};

int main() {
    return 0;
}
