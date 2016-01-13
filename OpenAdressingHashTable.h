#pragma once

class OpenAdressingHashTable {
private:
	int capacity;
	int *data;
	void recreate();
	int hash(int element);
public:
	OpenAdressingHashTable(int size);
	~OpenAdressingHashTable();
	bool search(int element, int& pos, int &times);
	int insert(int element);
};

