#include "DisjointSet.h"
#include "DataStructAndAlgorithm.h"

DisjointSet::DisjointSet(int _capacity)
{
	father = new int[_capacity];
	for (int i = 0; i < _capacity; i++)
	{
		father[i] = i;
	}
	for (int i = 0; i < _capacity; i++)
	{
		father[i] = i;
	}
}

DisjointSet::~DisjointSet()
{
	delete[] father;
	delete[] rank;
}

bool DisjointSet::merge(int element1, int element2)
{
	int ancestor1 = find_set(element1);
	int ancestor2 = find_set(element2);
	if (ancestor1 == ancestor2)
	{
		return false;
	}
	else
	{
		if (rank[ancestor1] > rank[ancestor2])
		{
			swap(ancestor1, ancestor2);
		}
		father[ancestor1] = ancestor2;
		rank[ancestor2] = max(rank[ancestor2], rank[ancestor1] + 1);
		return true;
	}
}

int DisjointSet::find_set(int element)
{
	int ancestor = element;
	if (ancestor != father[ancestor])
	{
		father[ancestor] = find_set(father[ancestor]);
	}
	return father[ancestor];
}
