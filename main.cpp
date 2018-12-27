//Diyane Fernando
//Student ID: 20743873
#include <iostream>
#include <cstdlib>
#include "RecordsManager.h"
#include "RecordsManagerTest.h"

using namespace std;

int main()
{
	RecordsManagerTest test;
	test.insert_remove();
    test.removal_insert_empty_list();
	test.removal_of_non_existing_record();
	test.insertion_to_full_list();
	test.removal_from_quarter_filled_list();

	return 0;
}
