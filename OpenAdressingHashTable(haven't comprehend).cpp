#include "OpenAdressingHashTable.h"
#include "DataStructAndAlgorithm.h"

OpenAdressingHashTable::OpenAdressingHashTable(int size) : capacity(size) {
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = -1;
	}
}


OpenAdressingHashTable::~OpenAdressingHashTable() {
	delete[] data;
}

//通过参数传多个返回值回去
bool OpenAdressingHashTable::search(int element,int& pos,int &times) {
	pos = hash(element);
	times = 0;
	while (data[pos] != -1 && data[pos] != element) {
		times++;
		if (times < capacity) {
			pos = (pos + 1) % capacity;
		}
		else
		{
			return false;
		}
	}
	if (element == data[pos]) {
		return true;
	}
	else
	{
		return false;
	}
	return 0;
}


int OpenAdressingHashTable::insert(int element) {
	int pos,times;
	if (search(element, pos, times))
	{
		return 2;
	}
	else
	{
		if (times < capacity / 2)
		{
			data[pos] = element;
			return 1;
		}
		else
		{
			recreate();
			return 0;
		}
	}
}


void OpenAdressingHashTable::recreate() {
	cout << "recreate" << endl;
	int *temp = data;
	int backup_capactiy = capacity;
	capacity *= 2;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		data[i] = -1;
	}
	//insert之前一定要把capacity设置为正确的值
	for (int i = 0; i < backup_capactiy; i++) {
		//如果在recreate的过程中又发生recreate怎么办
		if (temp[i] != -1) {
			insert(temp[i]);
		}
	}
	delete[] temp;
}

int OpenAdressingHashTable::hash(int element) {
	return element % capacity;
}