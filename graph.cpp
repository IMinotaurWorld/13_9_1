#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph() {
    for(int i=0;i < SIZE; i++)
      for(int j=0; j< SIZE; j++)
        matrix[i][j] = 0;
    for(int i = 0;i < SIZE;i++) vertexes[i] = "NONE";
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(string name)
{
    vertexes[vertexCount] = name;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2)
{
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(string v)
{
    for(int i=0;i<vertexCount;i++)
       if(vertexes[i] == v)
          return true;
    return false;
}

void Graph::allTripleFriends()
{
	bool visited[SIZE];
	for(int i = 0;i < vertexCount;i++){
		for(int i =0; i<SIZE; i++) visited[i] = false; // инициализируем как непосещенные
		tripleFriends(i, i, visited, 0);
		cout << "Friends " << vertexes[i] << ": " << "\n";
		for(int j = 0;j < SIZE;j++){
			if(j == i) continue;
			if(visited[j]) cout << " " << vertexes[j] << "\n";
		}
	}
}

void Graph::tripleFriends(int v, int current, bool visited[], int count)
{
	visited[current]= true; // помечаем как посещенную
	if(count >= 3) return;
    for(int i=0; i<SIZE; i++)
    {
        if(edgeExists(current,i) && !visited[i])
            tripleFriends(v, i, visited, count + 1); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину
    }
}
