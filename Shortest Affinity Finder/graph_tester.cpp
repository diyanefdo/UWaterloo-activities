#ifndef GRAPH_TESTER
#define GRAPH_TESTER

#include "weightedGraph.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class graph_Tester{
	public:
		bool test1(){
			weightedGraph tester(10);
			int graph[10][10]={
        	            {0, 1, 0, 0, 0, 0, 0, 3, 0, 9},
            	        {1, 0, 7, 0, 0, 0, 0, 0, 2, 0},
                	    {0, 7, 0, 6, 0, 0, 1, 8, 0, 0},
                    	{0, 0, 6, 0, 10,4, 7, 0, 0, 0},
                      	{0, 0, 0, 10,0, 2, 0, 0, 0, 0},
                      	{0, 0, 0, 4, 2, 0, 6, 0, 0, 0},
                      	{0, 0, 1, 7, 0, 6, 0, 5, 0, 0},
                      	{3, 0, 8, 0, 0, 0, 5, 0, 6, 0},
                      	{0, 2, 0, 0, 0, 0, 0, 6, 0, 2},
                      	{9, 0, 0, 0, 0, 0, 0, 0, 2, 0},
                     };
  
    	tester.dijkstra(graph, 0);
    		return true;
		}
		
		bool test2(){
			weightedGraph tester(10);
			return 0;
		}
		
		bool test3(){
			
			return 0;
		}
		
		bool test4(){
			
			return 0;
		}
};

#endif
