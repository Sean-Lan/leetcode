/**
 *
 * Sean
 * 2016-11-24
 *
 * https://leetcode.com/problems/nim-game/
 *
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 *
 * Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
 *
 * For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 *
 * Hint:
 *
 * If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?
 *
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
    vector<int> cache;
    bool helper(int n) {
	if (n <= 0) return false;
	if (cache[n] != -1) return cache[n];
	for (int i=1; i<=3; ++i) {
	    if (!helper(n-i)) {
		cache[n] = true;
		return true;
	    }
	}
	cache[n] = false;
	return false;
    }

public:
    bool canWinNim(int n) {
	if(n >= 134882061) {
	    return n % 4 != 0;
	}
	cache = vector<int>(n+1, -1);
	if (n <= 3) return true;
	return helper(n);
    }
};

int main() {
    return 0;
}
