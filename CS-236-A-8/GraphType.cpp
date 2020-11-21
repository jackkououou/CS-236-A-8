#include "GraphType.h"
#include <iostream>
#include <list>


GraphType::GraphType()
{

}

bool GraphType::isEmpty() const
{
	bool empty = true;
	for (int i = 0; i < gSize; i++)
	{
		if (graph[i][0] != NULL)
			empty = false;
	}
	return empty;
}

void GraphType::createGraph(std::vector < std::vector<int>> adjList)
{
	for (int i = 0; i < gSize; i++)
	{
		for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
		{
			addEdge(graph, i, *j);
		}
	}
}

void GraphType::addEdge(std::vector<int> list[], int i, int j)
{
	list[i].push_back(j);
}

void GraphType::printGraph()
{
	for (int i = 0; i < gSize; ++i)
	{
		std::cout << "\n Adjacency list of vertex "
			<< i << "\n head ";
		for (unsigned int j = 0; j < graph[i].size(); j++)
			std::cout << "-> " << graph[i][j];
		printf("\n");
	}
}


//Takes int value from vertex and uses switch to print city name
void GraphType::printVertexName(int vertex)
{
	switch (vertex)
	{
	case 0:
		std::cout << "Seattle ";
		break;
	case 1:
		std::cout << "San Francisco ";
		break;
	case 2:
		std::cout << "Los Angeles ";
		break;
	case 3:
		std::cout << "Denver ";
		break;
	case 4:
		std::cout << "Kansas ";
		break;
	case 5:
		std::cout << "Chicago ";
		break;
	case 6:
		std::cout << "Boston ";
		break;
	case 7:
		std::cout << "New York ";
		break;
	case 8:
		std::cout << "Atlanta ";
		break;
	case 9:
		std::cout << "Miami ";
		break;
	case 10:
		std::cout << "Dallas ";
		break;
	case 11:
		std::cout << "Houston ";
		break;
	default:
		std::cout << "Error... invalid vertex value." << std::endl;
	}
}

void GraphType::depthFirstTraversal(int initial_vertex)
{
	bool* visited = new bool[gSize];
	for (int i = 0; i < gSize; i++)
		visited[i] = false;

	depthFirstUtility(initial_vertex, visited);
}
void GraphType::breadthFirstTravel(int vertex)
{
	bool *visited = new bool[gSize];
	for (int i = 0; i < gSize; i++)
	visited[i] = false;

	std::list<int> queue;

	visited[vertex] = true;
	queue.push_back(vertex);

	while (!queue.empty())
	{
		vertex = queue.front();
		printVertexName(vertex);
		queue.pop_front();
		
		for (auto i = graph[vertex].begin(); i != graph[vertex].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}

	}

}

//bool *visited = new bool[gSize];
//for (int i = 0; i < gSize; i++)
//	visited[i] = false;
//std::vector<int> path_list;
//breadthFirstUtility(initial_vertex, visited, path_list);

void GraphType::depthFirstUtility(int vertex, bool visited[])
{
	visited[vertex] = true;
	printVertexName(vertex);
	std::cout << ' ';
	int temp;
	for (unsigned int i = 0; i < graph[vertex].size(); i++)
	{
		temp = graph[vertex][i];
		if (!visited[temp])
			depthFirstUtility(temp, visited);
	}
}

void GraphType::breadthFirstUtility(int vertex, bool visited[], std::vector<int> path_list)
{
	if (!visited[vertex])
	{
		visited[vertex] = true;
		printVertexName(vertex);
	}

	bool fresh_layer = false;
	int adj_vertex;
	for (unsigned int i = 0; i < graph[vertex].size(); i++)
	{
		adj_vertex = graph[vertex][i];
		if (!visited[adj_vertex])
		{
			visited[adj_vertex] = true;
			fresh_layer = true;
			printVertexName(adj_vertex);
		}
	}

	

}