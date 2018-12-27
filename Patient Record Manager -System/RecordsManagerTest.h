//Diyane Fernando
//Student ID: 20743873
#ifndef RECORDSMANAGERTEST_H
#define RECORDSMANAGERTEST_H
#include "RecordsManager.h"

class RecordsManagerTest
{
	private: 
		RecordsManager list1;
		RecordsManager emptyList;
		
	public:
		RecordsManagerTest();
		bool insert_remove();
		bool removal_insert_empty_list();
		bool removal_of_non_existing_record();
		bool insertion_to_full_list();
		bool removal_from_quarter_filled_list();
};

#endif
