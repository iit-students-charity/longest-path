#include "stdafx.h"
#include "Graph.h"



void graph::add_node(void)
{
	list.resize(list.size() + 1);
	return;
}



void graph::add_edge(int fromNode, int toNode, int weight)
{
	int difference = 0;

	if (fromNode > list.size())
	{
		difference = fromNode - list.size();
		for (size_t i = 0; i < difference; i++)
			add_node();
	}
	if (toNode > list.size())
	{
		difference = toNode - list.size();
		for (size_t i = 0; i < difference; i++)
			add_node();
	}

	list[fromNode - 1].resize(list[fromNode - 1].size() + 1);
	list[fromNode - 1][list[fromNode - 1].size() - 1].toNode = toNode;
	list[fromNode - 1][list[fromNode - 1].size() - 1].weight = weight;
	return;
}



void graph::clear(void)
{
	list.clear();
	return;
}



void graph::longest_path(int firstNode, int secondNode)
{
	vector<int> path;
	path.reserve(EDGES);
	longestPathLength = M_INF;
	int length = 0;
	path_next(firstNode, secondNode, length, path);

	return;
}

void graph::path_next(int node, int direction, int length, vector<int> path)
{
	vector<int> toGo;
	int nextNode;
	int weight;
	bool visited;
	path.push_back(node);

	if (node == direction)
	{
		if (length >= longestPathLength)
		{
			longestPath = path;
			longestPathLength = length;
			return;
		}
		return;
	}

	for (size_t i = 0; i < list[node - 1].size(); i++)
	{
		visited = false;
		for (size_t j = 0; j < path.size(); j++)
		{
			if (list[node - 1][i].toNode == path[j])
			{
				visited = true;
				break;
			}
		}
		if (!visited)
			toGo.push_back(list[node - 1][i].toNode);
	}

	while (toGo.size() != 0)
	{
		nextNode = toGo.back();
		toGo.pop_back();
		for (size_t i = 0; i < list[node - 1].size(); i++)
			if (list[node - 1][i].toNode == nextNode)
			{
				weight = list[node - 1][i].weight;
				length += weight;
				break;
			}

		path_next(nextNode, direction, length, path);
		length -= weight;
	}
	return;
}



int graph::get_longest_path_length(void)
{
	if (longestPathLength != M_INF)
		return longestPathLength;
	else
		return 0;
}



void graph::print_path(void)
{
	for (size_t i = 0; i < longestPath.size(); i++)
	{
		cout << longestPath[i];
		if (i != longestPath.size() - 1)
		{
			cout << " --[";
			for (size_t j = 0; j < list[longestPath[i] - 1].size(); j++)
			{
				if (list[longestPath[i] - 1][j].toNode == longestPath[i + 1])
				{
					cout << list[longestPath[i] - 1][j].weight << "]--> ";
					break;
				}
			}
		}
	}
	return;
}



void graph::print_list(void)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		cout << i + 1 << ": ";
		for (size_t j = 0; j < list[i].size(); j++)
		{
			cout << list[i][j].toNode << "(" << list[i][j].weight << "), ";
		} 
		cout << endl;
	}
	return;
}