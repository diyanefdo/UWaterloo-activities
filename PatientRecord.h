//Diyane Fernando
//Student ID: 20743873
#ifndef PATIENTRECORD_H
#define PATIENTRECORD_H

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class PatientRecord
{
	private:
		unsigned int category_ID;
		unsigned int patient_ID;
		string name;
		string address;
		string DOB;

	public:
		PatientRecord();
		PatientRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB);
		int getCatID();
		int getPatID();
		string getName();
		string getAddress();
		string getDOB();
		void setCatID(int NewCatID);
		void setPatID(int NewPatID);
		void setName(string NewName);
		void setAddress(string NewAddress);
		void setDOB(string NewDOB);

};

#endif
