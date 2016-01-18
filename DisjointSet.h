#pragma once

class DisjointSet
{
public:
	DisjointSet(int _capacity);
	~DisjointSet();
	bool merge(int element1, int element2);
	int find_set(int element);
private:
	int *father;
	int *rank;
};