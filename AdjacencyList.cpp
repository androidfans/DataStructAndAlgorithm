#include "AdjacencyList.h"
#include <functional>
#include <limits>

Graph::Graph(int _size) : size(_size)
{
	edges = new list<int>[size];
	visited = new bool[size];
	memset(visited, 0, size * sizeof(bool));
	path = new int[size];
	memset(path, 0, size * sizeof(int));
	collected = new bool[size];
	memset(collected, 0, size * sizeof(bool));
	dist = new int[size];
	int max = numeric_limits<int>::max();
	for (int i = 0; i < size; i++)
	{
		dist[i] = max;
	}
}

Graph::~Graph()
{
	delete[] edges;
	delete[] visited;
	delete[] dist;
}

void Graph::insert_edge(int x, int y)
{
	edges[x].push_back(y);
	edges[y].push_back(x);
}

void Graph::dfs(int start)
{
	cout << start << " ";
	visited[start] = true;
	list<int> &adjs = edges[start];
	for (auto it = adjs.begin(); it != adjs.end(); it++)
	{
		if (!visited[*it])
		{
			dfs(*it);
		}
	}
}

void Graph::bfs(int start)
{
	queue<int> queue;
	queue.push(start);
	visited[start] = true;
	int temp;
	while (!queue.empty())
	{
		temp = queue.front();
		queue.pop();
		cout << temp << " ";
		list<int> &adjs = edges[temp];
		for (auto it = adjs.begin(); it != adjs.end(); it++)
		{
			if (!visited[*it])
			{
				queue.push(*it);
				visited[*it] = true;
			}
		}
	}
}

void Graph::dijkstra(int start)
{
	dist[start] = 0;
	while (true)
	{
		int min_value = -1;
		for (int i = 0; i < size; i++)
		{
			if (!collected[i])
			{
				min_value = min(dist[i], min_value);
			}
		}
		if (min_value == -1)
		{
			return;
		}
		list<int> &adjs = edges[min_value];
		for (auto it = adjs.begin(); it != adjs.end(); it++)
		{
			if (!collected[*it])
			{
				if (dist[min_value] + *it < dist[*it])
				{
					dist[*it] = dist[min_value] + *it;
					path[*it] = min_value;
				}
			}
		}
	}
}
