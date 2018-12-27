#include <iostream>
#include <cstdlib>
#include <string>
#include "weightedGraph.cpp"

using namespace std;

string get_status_str(bool status) {
    return status ? "TEST PASSED" : "TEST FAILED";
}


int main() {
	
	graph_Tester tester;
	cout << "Welcome to affinity graph maker" << endl << "================================" << endl;
	string test_descriptions[4] = {
      "Test1: New empty graph is valid",
      "Test2: insert() works properly",
      "Test3: search() works properly",
	  "Test4: outputs the proper distances between nodes",
	};
	
	bool test_results[4];
    test_results[0] = tester.test1();
    test_results[1] = tester.test2();
    test_results[2] = tester.test3();
    test_results[3] = tester.test4();


	cout << "GRAPH TESTER TEST RESULTS \n";
	cout << "*************************** \n";
	for (int i = 0; i < 4; ++i) {
    	cout << test_descriptions[i] << endl << get_status_str(test_results[i]) << endl;
	}
    system("pause");
    
    return true;
}
