//Diyane Fernando
//Student ID: 20743873
#ifndef RECORDSMANAGER_H
#define RECORDSMANAGER_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "PatientRecord.h"

using namespace std;

class RecordsManager
{
	private:
		int size;
		int capacity;
		PatientRecord** data;


	public:
		RecordsManager();
		RecordsManager(int nCap);
		int getSize();
		int getCapacity();
		friend class RecordsManagerTest;
		void print();
		bool insertRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB);
		bool removeRecord(unsigned int categoryID, unsigned int patientID);
		~RecordsManager();
};

#endif
