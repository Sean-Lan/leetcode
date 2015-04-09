/**
 *
 * Sean
 * 2015-04-09
 *
 * https://leetcode.com/problems/add-two-numbers/
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 *
 * Use curNode and cnt to save the state when traversing the linked list.
 * Remeber to calculate the tail linked list.
 *
 * Practice managing the memory manully.
 *
 * Node the initializer list is a C++11 feature, so you may be add "-std=c++11"
 * to enable it.
 *
 */

class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			cnt = 0;
			int oneBitResult = l1->val + l2->val;
			cnt = oneBitResult/10;
			oneBitResult %= 10;
			curNode= new ListNode(oneBitResult);
			result = curNode;
			l1 = l1->next;
			l2 = l2->next;

			while(l1 && l2) {
				oneBitResult =l1->val + l2->val + cnt;
				l1 = l1->next;
				l2 = l2->next;
				cnt = oneBitResult/10;
				oneBitResult %= 10;
				ListNode *newNode = new ListNode(oneBitResult);
				curNode->next = newNode;
				curNode = newNode;
			}

			addTail(l1);
			addTail(l2);


			if(cnt) {
				ListNode *newNode = new ListNode(cnt);
				curNode->next = newNode;
				curNode = newNode;
			}
			return result;
		}
	private:
		ListNode *curNode;
		ListNode *result;
		int cnt;
		void addTail(ListNode *pNode) {
			int oneBitResult;
			while(pNode) {
				oneBitResult = pNode->val + cnt;
				pNode = pNode->next;
				cnt = oneBitResult/10;
				oneBitResult %= 10;
				ListNode *newNode = new ListNode(oneBitResult);
				curNode->next = newNode;
				curNode = newNode;
			}
		}
};

void printLinkedList(ListNode *head) {
	cout << head->val;
	head = head->next;
	while(head) {
		cout << " -> " << head->val;
		head = head->next;
	}
	cout << endl;
}

ListNode* constructLinkedList(vector<int>& ivec) {
	ListNode *head = NULL;
	ListNode *curNode = NULL;
	if (ivec.size()) {
		head = curNode = new ListNode(ivec[0]);
	}
	for (int i = 1; i<ivec.size(); ++i) {
		ListNode *newNode = new ListNode(ivec[i]);
		curNode->next = newNode;
		curNode = newNode;
	}
	return head;
}

void destructLinkedList(ListNode* head) {
	ListNode *next = head->next;
	while(next) {
		delete head;
		head = next;
		next = head->next;
	}
	delete head;
}


int main() {
	vector<int> ivec1 = {3, 9, 9, 1};
	vector<int> ivec2 = {7};
	ListNode *l1 = constructLinkedList(ivec1);
	ListNode *l2 = constructLinkedList(ivec2);
	printLinkedList(l1);
	printLinkedList(l2);

	Solution s;
	ListNode *result = s.addTwoNumbers(l1, l2);
	printLinkedList(result);
	destructLinkedList(l1);
	destructLinkedList(l2);
	destructLinkedList(result);
	return 0;
}
