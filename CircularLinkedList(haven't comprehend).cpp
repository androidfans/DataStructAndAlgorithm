#include "DataStructAndAlgorithm.h"

class LinkedListNode {
public:
	int data;
	LinkedListNode *next = NULL;
	LinkedListNode(int _data) {
		data = _data;
	}
};

class CircularLinkedList {
public:
	LinkedListNode* find(int index) {
		if (head == NULL) {
			return NULL;
		}
		LinkedListNode *current_node = head->next;
		int count = 0;
		while (current_node != head&&count != index) {
			current_node = current_node->next;
			count++;
		}
		if (count == index) {
			return current_node;
		}
		return NULL;
	}

	void insert(LinkedListNode *node, int index) {
		if (head == NULL) {
			head = node;
			head->next = head;
			return;
		}
		if (index == 0) {
			node->next = head->next;
			head->next = node;
			return;
		}
		LinkedListNode *pre_node = find(index - 1);
		if (pre_node != NULL) {
			node->next = pre_node->next;
			pre_node->next = node;
		}
		if (node == head->next) {
			head = node;
		}
	}

	void remove(int index) {
		if (head == NULL) {
			return;
		}
		LinkedListNode *delete_node = NULL;
		if (index == 0) {
			delete_node = head->next;
			head->next = delete_node->next;
			delete delete_node;
			return;
		}
		LinkedListNode *pre_node = find(index - 1);
		if (!pre_node) {
			return;
		}
		if (pre_node == head) {
			return;
		}
		delete_node = pre_node->next;
		pre_node->next = delete_node->next;
		if (delete_node == head) {
			head = pre_node;
		}
		delete delete_node;
	}

	void reverse() {
		if (head == NULL) {
			return;
		}
		LinkedListNode *current_node = head->next;
		LinkedListNode *next_node = NULL;
		LinkedListNode *origin_head = head;
		LinkedListNode *origin_next = head->next;
		do {
			next_node = current_node->next;
			current_node->next = head;
			head = current_node;
			current_node = next_node;
		} while (head != origin_head);
		head = origin_next;
	}

	void output() {
		if (head == NULL) {
			cout << "Linked List is NULL" << endl;
		}
		LinkedListNode *current_node = head->next;
		do {
			cout << current_node->data << " ";
			current_node = current_node->next;
		} while (current_node != head->next);
		cout << endl;
	}
private:
	LinkedListNode *head = NULL;
};