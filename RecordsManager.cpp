//Diyane Fernando
//Student ID: 20743873
#include "RecordsManager.h"

RecordsManager::RecordsManager()
{
	capacity = 128;  //change value to 6 for testing
	data = new PatientRecord*[capacity];
	size = 0;
}

RecordsManager::RecordsManager(int nCap)
{
	if(nCap <128) //change value to 6 for testing
		capacity = 128;  //change value to 6 for testing
	else
		capacity = nCap;
	data = new PatientRecord*[capacity];
	size =0;
}
int RecordsManager::getSize()
{
	return size;
}

int RecordsManager::getCapacity()
{
	return capacity;
}

void RecordsManager::print()
{
	for(int i = 0; i<size; i++)
	{
		cout<<setw(6)<<(*data[i]).getCatID()<<setw(6)<<(*data[i]).getPatID()<<
		setw(20)<<(*data[i]).getName()<<setw(15)<<(*data[i]).getAddress()<<setw(13)<<
		(*data[i]).getDOB()<<endl;
	}
}

bool RecordsManager::insertRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB)
{
	for(int i =0; i<size; i++)
	{
		if((*data[i]).getCatID() == newCatID && (*data[i]).getPatID()==newPatID)
			return false;
	}
    if(size+1 > capacity)
    {
        capacity *=2;
        PatientRecord** temp = new PatientRecord*[capacity];
        for(int i =0; i<size; i++)
        {
            temp[i] = data[i];
            data[i] = NULL;
        }
        delete [] data;
        data = temp;
        temp = NULL;
    }
	data[size] = new PatientRecord;
	(*data[size]).setCatID(newCatID);
	(*data[size]).setPatID(newPatID);
	(*data[size]).setName(newName);
	(*data[size]).setAddress(newAddress);
	(*data[size]).setDOB(newDOB);
	size++;

	for(int i = 0; i<size; i++)
	{
		for(int j =i; j<size; j++)
		{
			if((*data[i]).getCatID() > (*data[j]).getCatID())
			{
				PatientRecord* temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
			if((*data[i]).getCatID() == (*data[j]).getCatID() && (*data[i]).getPatID() > (*data[j]).getPatID())
			{
				PatientRecord* temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	return true;
}

bool RecordsManager::removeRecord(unsigned int categoryID, unsigned int patientID)
{
	int index = 0;
	while(index < size)
    {
        if(data[index]->getCatID() == categoryID && data[index]->getPatID() == patientID)
            break;
        index++;
    }

	if(index == size)
		return false;
	delete data[index];
	for(int i = index; i<size-1; i++)
	{
		data[i] = data[i+1];
	}
	data[size-1] = NULL;
	size--;
	if(size<(capacity/4) && (capacity/2)>=128) //change 128 to 6 for testing
		capacity/=2;
	else if(size<(capacity/4) && (capacity/2)<128) //change 128 to 6 for testing
		capacity = 128; //change capacity, 128 to 6 for testing
    PatientRecord** temp = new PatientRecord*[capacity];
    for(int i = 0; i<size; i++)
    {
        temp[i]= data[i];
        data[i] = NULL;
    }
    delete [] data;
    data = temp;
    temp = NULL;
	return true;
}

RecordsManager::~RecordsManager()
{
	for(int i =0; i<size; i++)
	{
		delete data[i];
	}
	delete [] data;
}






