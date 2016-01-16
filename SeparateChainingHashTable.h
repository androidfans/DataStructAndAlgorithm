#pragma once
#include "SinglelyLinkedList.h"
class SeparateChainingHashTable {
private:
	int capacity;
	SinglelyLinkedList *data;
	int hash(int element);
public:
	SeparateChainingHashTable(int size);
	~SeparateChainingHashTable();
	bool search(int element,int &pos);
	int insert(int element);
	void output();
};