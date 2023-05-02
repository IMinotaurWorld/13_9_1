#ifndef __GRAPH__
#define __GRAPH__

#define SIZE 30

#include <iostream>

using namespace std;


class Graph {
    public:
        Graph();
        // добавление вершины
        void addVertex(string vnumber);
        // добавление ребра
        void addEdge(int v1, int v2);
        
        void allTripleFriends();
    private:
        bool edgeExists(int v1, int v2);
        bool vertexExists(string v);
		
		void tripleFriends(int v, int current, bool visited[], int count);
		
        int matrix[SIZE][SIZE]; // матрица смежности
         
        string vertexes[SIZE]; // хранилище вершин
        int vertexCount; // количество добавленных вершин
		
};
#endif