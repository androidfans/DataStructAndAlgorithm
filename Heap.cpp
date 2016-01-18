#include "Heap.h"

Heap::Heap(int _capacity) : size(0) , capacity(_capacity)
{
	data = new int[_capacity];
}

Heap::~Heap()
{
	delete[] data;
}

bool Heap::push(int element)
{
	if (size + 1 >= capacity)
	{
		return false;
	}
	size++;
	int father = size / 2;
	int current = size;
	while (father > 0 && element > data[father])
	{
		data[current] = data[father];
		current = father;
		father = current / 2;
	}
	data[current] = element;
	return true;
}

bool Heap::pop()
{
	if (size <= 0)
	{
		return false;
	}
	swap(data[1], data[size]);
	size --;
	update();
	return false;
}

int Heap::top()
{
	if (size > 0)
	{
		return data[size];
	}
	return 0;
}

void Heap::output()
{
	for (int i = 1; i <= size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

void Heap::update()
{
	if (size == 2)
	{
		if (data[1] < data[2])
		{
			swap(data[1], data[2]);
		}
		return;
	}
	int current = 1;
	int max_child = current * 2;
	//没考虑到只有两个元素的情况
	while (max_child <= size &&data[current] < data[max_child])
	{
		if (data[max_child + 1] > data[max_child])
		{
			max_child++;
		}
		swap(data[current], data[max_child]);
		current = max_child;
		max_child = current * 2;
	}
}

void Heap::heap_sort()
{
	int copy_size = size;
	for (; size > 1; size--)
	{
		update();
		swap(data[1], data[size]);
	}
	size = copy_size;
}
