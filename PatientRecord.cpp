//Diyane Fernando
//Student ID: 20743873
#include "PatientRecord.h"

PatientRecord::PatientRecord()
{
	category_ID = 0;
	patient_ID = 0;
	name ="";
	address = "";
	DOB = "";
}

PatientRecord::PatientRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB)
{
	category_ID = newCatID;
	patient_ID = newPatID;
	name = newName;
	address = newAddress;
	DOB = newDOB;
}

int PatientRecord::getCatID()
{
	return category_ID;
}

int PatientRecord::getPatID()
{
	return patient_ID;
}

string PatientRecord::getName()
{
	return name;
}

string PatientRecord::getAddress()
{
	return address;
}

string PatientRecord::getDOB()
{
	return DOB;
}
	
void PatientRecord::setCatID(int NewCatID)
{
	category_ID = NewCatID;
}
void PatientRecord::setPatID(int NewPatID)
{
	patient_ID = NewPatID;
}
void PatientRecord::setName(string NewName)
{
	name = NewName;
}
void PatientRecord::setAddress(string NewAddress)
{
	address = NewAddress;
}
void PatientRecord::setDOB(string NewDOB)
{
	DOB = NewDOB;
}
	









