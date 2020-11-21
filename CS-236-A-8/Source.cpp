#include <iostream>
#include <vector>
#include "GraphType.h"

using namespace std;

int main()
{
	int choice;
	std::vector<std::vector<int>> adjList = {	{1,3,5},			{0,2,3},		{1,3,4,10},		{0,1,2,4,5},	// 0, 1, 2, 3,
												{2,3,5,7,8,10 },	{ 0,3,4,6,7 },	{ 5,7 },		{ 4,5,6,8 },	// 4, 5, 6, 7
												{4,7,9,10,11 },		{ 8,11 },		{ 2,4,8,11 },	{ 8,9,10 } };	// 8, 9, 10, 11
	
	GraphType G;
	G.createGraph(adjList);
	
	cout << "Graph Traversal!" << endl << endl;

	cout << "0	Seattle" << endl;
	cout << "1	San Fransisco" << endl;
	cout << "2	Los Angeles" << endl;
	cout << "3	Denver" << endl;
	cout << "4	Kansas" << endl;
	cout << "5	Chicago" << endl;
	cout << "6	Boston" << endl;
	cout << "7	New York" << endl;
	cout << "8	Atlanta" << endl;
	cout << "9	Miami" << endl;
	cout << "10	Dallas" << endl;
	cout << "11	Houston" << endl;
	cout << "-1	Exit Program" << endl << endl;
	do 
	{
		cout << "Enter starting city using number from 0 - 11: ";
		cin >> choice;
		cout << "You entered city name: ";
		G.printVertexName(choice);
		cout << endl << endl << "Starting at ";
		G.printVertexName(choice);
		cout << ", 12 cities are searched in this Depth-First Search order:" << endl;
		G.depthFirstTraversal(choice);
		cout << endl << endl << "Starting at ";
		G.printVertexName(choice);
		cout << ", 12 cities are searched in this Breadth-First Search order:" << endl;
		G.breadthFirstTravel(choice);
		cout << endl << endl;
		

	} while (choice != -1);




	return 0;
}