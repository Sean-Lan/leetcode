/**
 *
 * Sean
 * 2017-07-18
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/#/description
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
 *
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 *
 * Could you do this in O(n) runtime?
 *
 * Example:
 *
 * Input: [3, 10, 5, 25, 2, 8]
 *
 * Output: 28
 *
 * Explanation: The maximum result is 5 ^ 25 = 28.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// use Trie with two pointers, one for zero bit and another for one bit
// first build the trie, then for each num find the maximum value it can get through XOR
// down the tree
// two things to note:
// 1. the trie needs to be built from high bit to low bit
// 2. you may want to diretly get the max XOR value from the trie, but it's complicated
//    and you may need to visit the whole trie, instead, you can re-scan the array and test
//    the maximum value of each number down the trie
struct TrieNode {
    TrieNode *p0, *p1;
    TrieNode() {
        p0 = nullptr, p1 = nullptr;
    }
};

TrieNode *buildTrie(vector<int> &nums) {
    TrieNode *root = new TrieNode;
    for (auto &num : nums) {
        TrieNode *p = root;
        for (int i=30; i>=0; --i) {
            if (num & (1<<i)) {
                if (!p->p1) {
                    p->p1 = new TrieNode;
                }
                p = p->p1;
            } else {
                if (!p->p0) {
                    p->p0 = new TrieNode;
                }
                p = p->p0;
            }
        }
    }
    return root;
}

int getMaxXOR(TrieNode *root, int num) {
    int res = 0;
    int mask;
    TrieNode *p = root;
    for (int i=30; i>=0; --i) {
        mask = (1<<i);
        if (num & mask) {
            if (p->p0) {
                res |= mask;
                p = p->p0;
            } else {
                p = p->p1;
            }
        } else {
            if (p->p1) {
                res |= mask;
                p = p->p1;
            } else {
                p = p->p0;
            }
        }
    }
    return res;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = buildTrie(nums);
        int res = 0;
        for (auto &num : nums) {
            res = max(res, getMaxXOR(root, num));
        }
        return res;
    }
};

int main() {
    return 0;
}
