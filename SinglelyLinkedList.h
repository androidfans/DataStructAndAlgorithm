#pragma once
class Node {
public:
	int data;
	Node *next;
	Node(int _data);
};

class SinglelyLinkedList {
public:
	Node *head = nullptr;

	Node* find(int index);

	void insert(Node *node, int index);

	void remove(int index);

	void reverse();

	void output();
};