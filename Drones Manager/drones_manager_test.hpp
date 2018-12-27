#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// new empty list is valid
    bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
    }

	// insert_front() and insert_back() on zero-element list
    bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		
	    return true;
    }

	// select() and search() work properly
    bool test3() {
	    return false;
    }
    
    // remove_front() and remove_back() on one-element list
    bool test4() {
	    return false;
    }
    
    // replace() and reverse_list() work properly
    bool test5() {
	    return false;
    }
    
    // insert_front() keeps moving elements forward
    bool test6() {
	    return false;
    }
    
    // inserting at different positions in the list
    bool test7() {
 	    return false;
    }
    
    // try to remove too many elements, then add a few elements
    bool test8() {
	    return false;
    }
    
 	// lots of inserts and deletes, some of them invalid
	bool test9() {
		return false;
	}    
	    	
		// inserts into an unsorted list, then sort the list
	bool test10() {
	   return false;
	}  
	
		// insert and remove into sorted manager in ascending order
	bool test11() {
	   return false;
	}
	
	  //insert and remove into sorted manager in descending order
	bool test12() {
	   return false;
	}  
};


#endif
