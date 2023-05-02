#include <iostream>
#include "graph.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Graph* graph = new Graph();
	
	graph->addVertex("Vasya");
	graph->addVertex("Vitya");
	graph->addVertex("Misha");
	graph->addVertex("Sasha");
	graph->addVertex("Lesha");
	graph->addVertex("Dima");
	
	graph->addEdge(0, 1);
	graph->addEdge(1, 2);
	graph->addEdge(2, 3);
	graph->addEdge(3, 4);
	graph->addEdge(4, 5);
	
	graph->allTripleFriends();
	
	return 0;
}