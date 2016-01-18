#pragma once
#include "DataStructAndAlgorithm.h"
class Heap
{
public:
	Heap(int _capacity);
	~Heap();
	bool push(int element);
	bool pop();
	int top();
	int size;
	void output();
	void update();
	void heap_sort();
private:
	int *data;
	int capacity;
};