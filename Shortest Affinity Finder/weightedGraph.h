#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#define V 10

using namespace std;

class weightedGraph{
	private:
		int n;
		int ** adj;
		bool* visited;
		
	public:
		
		insert(string name1_, string name2_, int distance);
		
		int minDistance(int dist[], bool sptSet[]);
		
		void printDijkstra(int dist[], int n);
		
		void dijkstra(int graph[][V], int src);
		
		
};

#endif
