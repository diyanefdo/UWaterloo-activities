#include "weightedGraph.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#define V 10

using namespace std;

bool graph::insert(string name1_, string name2_, int distance){
	
	bool name1_exist = 0;
	bool name2_exist = 0;
	int index_name1 = 0;
	int index_name2 = 0;
	int count = 0;
	while(names[count] != "" && count <30)
	{
		if(names[count] == name1_){
			name1_exist = 1;
			index_name1 = count;
		}
		if(names[count] == name2_){
			name2_exist = 1;
			index_name2 = count;
		}
		count++;	
	}
	
	if(name1_exist ==0 && name2_exist == 0){
		names[count] = name1_;
		names[count+1]= name2_;
		index_name1 = count;
		index_name2 = count+1;
		
		size+= 2;
	}
	else if (name1_exist ==1 && name2_exist == 0){
		names[count] = name2_;
		index_name2 = count;
		size++;
	}
		
	else if (name1_exist ==0 && name2_exist == 1){
		names[count] = name1_;
		index_name1 = count;
		size++;
	}
		
	if(*(dist_dir[index_name1]+index_name2) != 0)
	return false; 
	
	else{
	*(dist_dir[index_name1]+index_name2) = distance;
	*(dist_dir[index_name2]+index_name1) = distance;
	
	return true; 
    }
}


int weightedGraph::minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}


void weightedGraph::printDijkstra(int dist[], int n){
	cout << "VERTEX   DISTANCE TO SOURCE" << endl;
	for(int i = 0; i < V; i++){
		cout << i << "\t\t" << dist[i] << endl;
	}
}

void weightedGraph::dijkstra(int graph[V][V], int src)
{
     int dist[V];     
     bool sptSet[V]; 
     
	 // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++){
    	dist[i] = INT_MAX;
		sptSet[i] = false;
	 }
    
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not processed
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
        if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u]+graph[u][v]) < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printDijkstra(dist, V);
}
