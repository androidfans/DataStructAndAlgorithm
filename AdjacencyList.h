#pragma once
#include "DataStructAndAlgorithm.h"	

class Graph
{
public:
	Graph(int _size);
	~Graph();
	void insert_edge(int x,int y);
	void dfs(int start);
	void bfs(int start);
	void dijkstra(int start);
private:
	list<int> *edges;
	int size;
	bool *visited;
	bool *collected;
	int *dist;
	int *path;
};