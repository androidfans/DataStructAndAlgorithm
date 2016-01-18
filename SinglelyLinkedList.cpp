#include "DataStructAndAlgorithm.h"
#include "SinglelyLinkedList.h"

LinkedListNode::LinkedListNode(int _data) : next(nullptr), data(_data) {

}

LinkedListNode* SinglelyLinkedList::find(int index) {
	if (head == NULL) {
		return NULL;
	}
	LinkedListNode *current_node = head;
	int count = 0;
	while (current_node != NULL&&count != index) {
		current_node = current_node->next;
		count++;
	}
	if (count == index) {
		return current_node;
	}
	return NULL;
}

void SinglelyLinkedList::insert(LinkedListNode *node, int index) {
	if (head == NULL) {
		head = node;
		return;
	}
	if (index == 0) {
		node->next = head;
		head = node;
	}
	LinkedListNode *pre_node = find(index - 1);
	if (pre_node != NULL) {
		node->next = pre_node->next;
		pre_node->next = node;
	}
}

void SinglelyLinkedList::remove(int index) {
	if (head == NULL) {
		return;
	}
	LinkedListNode *delete_node = NULL;
	if (index == 0) {
		delete_node = head;
		head = head->next;
		delete delete_node;
		return;
	}
	LinkedListNode *pre_node = find(index - 1);
	delete_node = pre_node->next;
	pre_node->next = delete_node->next;
	delete delete_node;
}

void SinglelyLinkedList::reverse() {
	if (head == NULL) {
		return;
	}
	LinkedListNode *current_node = head->next;
	LinkedListNode *next_node = NULL;
	head->next = NULL;
	while (current_node != NULL) {
		next_node = current_node->next;
		current_node->next = head;
		head = current_node;
		current_node = next_node;
	}
}

void SinglelyLinkedList::output() {
	if (head == NULL) {
		cout << "Linked List is NULL" << endl;
	}
	LinkedListNode *current_node = head;
	while (current_node != NULL) {
		cout << current_node->data << " ";
		current_node = current_node->next;
	}
	cout << endl;
}
