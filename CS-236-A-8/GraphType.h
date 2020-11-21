#pragma once
#include <vector>
#include <iostream>
class GraphType
{
public:

	bool isEmpty() const;
	void createGraph(std::vector < std::vector<int>> adjList);
	void depthFirstTraversal(int initial_vertex);
	void breadthFirstTravel(int initial_vertex);
	void printVertexName(int vertex);
	
	void printGraph();
	GraphType();
	~GraphType() {};
	
private:
	void addEdge(std::vector<int> list[], int i, int j);
	void depthFirstUtility(int vertex, bool visited[]);
	void breadthFirstUtility(int vertex, bool visited[], std::vector<int> path_list);
	


	const int gSize = 12;
	std::vector<int> graph[12];
};


