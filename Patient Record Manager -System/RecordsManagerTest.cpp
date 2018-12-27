//Diyane Fernando
//Student ID: 20743873
#include "RecordsManagerTest.h"

RecordsManagerTest::RecordsManagerTest()
{
	list1.insertRecord(113,111,"Diyane Fernando","Waterloo", "16-03-1999");
	list1.insertRecord(115,1,"Louise rickon","missisauga", "14-03-1979");
	list1.insertRecord(112,6,"Amanda hedron","Toronto", "12-09-1969");
	list1.insertRecord(115,8,"emilia stark","winnipeg", "26-08-1998");


}

bool RecordsManagerTest::insert_remove()
{
	cout<<"TESTING THE INSERTION AND REMOVAL OF A RECORD TO THE LIST:"<<endl<<endl;
	cout<<"NOTE: The default capacity of the list has been set to 6"<<endl<<endl;
	cout<<"Before insertion of record:"<<endl;
	list1.print();
	cout<< "Size: "<<list1.getSize()<<" | " <<"Capacity: "<<list1.getCapacity()<<endl;
	cout<<endl<<"After insertion:"<<endl;
	list1.insertRecord(114,89,"Dave starman","Vancouver", "11-11-1991");
	list1.print();
	cout<< "Size: "<<list1.getSize()<<" | " <<"Capacity: "<<list1.getCapacity()<<endl;
	cout<<endl<<"After removal:"<<endl;
	list1.removeRecord(115,1);
	list1.print();
	cout<< "Size: "<<list1.getSize()<<" | " <<"Capacity: "<<list1.getCapacity()<<endl<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	return true;
}

bool RecordsManagerTest::removal_insert_empty_list()
{
	cout<<"REMOVAL OF RECORD FROM EMPTY LIST: "<<endl;
	if(emptyList.removeRecord(115,63) == 0 && emptyList.getSize() == 0 )
		cout<<"Removal unsuccessful as record does not exist."<<endl;
	cout<< "Size: "<<emptyList.getSize()<<" | " <<"Capacity: "<<emptyList.getCapacity()<<endl<<endl;
	cout<<"ADDITION OF RECORD TO EMPTY LIST: "<<endl<<endl;
	emptyList.insertRecord(124,19,"Brent Branson","Kitchener","03-12-1974");
	emptyList.print();
	cout<< "Size: "<<emptyList.getSize()<<" | " <<"Capacity: "<<emptyList.getCapacity()<<endl<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	return true;

}

bool RecordsManagerTest::removal_of_non_existing_record()
{
	cout<<"TESTING THE REMOVAL OF A RECORD THAT DOES NOT EXIST:"<<endl<<endl;
	cout<<"Record to be removed: "<<endl;
	emptyList.print(); cout<<endl;
	cout<<"Before removal of record:"<<endl;
	list1.print();
    if( list1.removeRecord(124,19) == false && list1.getSize()!= 0)
		cout<<"Record does not exist in the list !"<<endl;
	cout<< "Size: "<<list1.getSize()<<" | " <<"Capacity: "<<list1.getCapacity()<<endl<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	return true;
}

bool RecordsManagerTest::insertion_to_full_list()
{
	list1.insertRecord(12,26,"Gary scott","Bangalore", "19-04-2000");
	list1.insertRecord(17,17,"tony start","Malibu", "19-04-1979");
	cout<<"ADDITION OF RECORD TO FULL LIST: " <<endl<<endl;
	cout<<"Before addition of record:"<<endl;
	list1.print();
	cout<< "Size: "<<list1.getSize()<<" | " <<"Capacity: "<<list1.getCapacity()<<endl<<endl;
	cout<<"After insertion: "<<endl;
	list1.insertRecord(26, 19, "Bruce Wayne","Gotham","20-07-1980");
	list1.print();
	cout<<"Size: "<<list1.getSize()<<" | "<<"Capacity: "<<list1.getCapacity()<<endl<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	return true;
}

bool RecordsManagerTest::removal_from_quarter_filled_list()
{
	list1.removeRecord(113,111);
	list1.removeRecord(17,17);
	list1.removeRecord(114,89);
	list1.removeRecord(112,6);
	cout<<"REMOVAL OF RECORD FROM A QUARTER FILLED LIST: " <<endl<<endl;
	cout<<"Before removal: "<<endl;
	cout<<"Size: "<<list1.getSize()<<" | "<<"Capacity: "<<list1.getCapacity()<<endl<<endl;
	cout<<"After removal: "<<endl;
	list1.removeRecord(26,19);
	cout<<"Size: "<<list1.getSize()<<" | "<<"Capacity: "<<list1.getCapacity()<<endl<<endl;
	cout<<"------------------------------------------------------------"<<endl;
}





