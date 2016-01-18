#pragma once
class LinkedListNode {
public:
	int data;
	LinkedListNode *next;
	LinkedListNode(int _data);
};

class SinglelyLinkedList {
public:
	LinkedListNode *head = nullptr;

	LinkedListNode* find(int index);

	void insert(LinkedListNode *node, int index);

	void remove(int index);

	void reverse();

	void output();
};