#include "SeparateChainingHashTable.h"
#include "SinglelyLinkedList.h"
#include "DataStructAndAlgorithm.h"


SeparateChainingHashTable::SeparateChainingHashTable(int size) {
	capacity = size;
	data = new SinglelyLinkedList[size];
}

SeparateChainingHashTable::~SeparateChainingHashTable() {
	delete[] data;
}

int SeparateChainingHashTable::hash(int element) {
	return element % capacity;
}

bool SeparateChainingHashTable::search(int element,int &pos) {
	pos = hash(element);
	SinglelyLinkedList &list = data[pos];
	for (Node *node = list.head; node != nullptr; node = node->next) {
		if (node->data == element) {
			return true;
		}
	}
	return false;
}

int SeparateChainingHashTable::insert(int element) {
	int pos;
	if (search(element, pos)) {
		return pos;
	}
	else
	{
		Node *node = new Node(element);
		pos = hash(element);
		SinglelyLinkedList &list = data[pos];
		if (list.head == nullptr) {
			list.head = node;
		}
		else
		{
			Node *pre_node;
			for (pre_node = list.head; pre_node->next != nullptr; pre_node = pre_node->next);
			node->next = pre_node->next;
			pre_node->next = node;
		}
	}
}

void SeparateChainingHashTable::output() {
	for (int i = 0; i < capacity; i++) {
		SinglelyLinkedList list = data[i];
		cout << i << " :";
		for (Node *node = list.head; node != nullptr; node = node->next) {
			cout << node->data << (node->next == nullptr?"":"<-");
		}
		cout << endl;
	}
}