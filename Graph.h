#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define EDGES 10
#define NODES 10
#define M_INF -2147483647



class graph
{
public:
	graph(void)
	{
		list.resize(0);
		list.reserve(NODES);
		longestPath.resize(0);
		longestPath.reserve(EDGES);
		longestPathLength = M_INF;
	}
	~graph(void)
	{
		list.clear();
		longestPath.clear();
		longestPathLength = NULL;
	}

	void add_node(void);
	void add_edge(int fromNode, int toNode, int weight);
	void clear(void);
	void longest_path(int firstNode, int secondNode);
	void print_list(void);
	void print_path(void);
	int get_longest_path_length(void);
private:
	struct edge
	{
		int toNode;
		int weight;
	};
	vector<vector<edge>> list;

	vector<int> longestPath;
	int longestPathLength;

	void path_next(int node, int direction, int length, vector<int> path);
};