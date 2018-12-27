#include "drones_manager.hpp"

DronesManager::DronesManager() {
	first = NULL;
	last = NULL;
	size =0;
}

DronesManager::~DronesManager() {
	DroneRecord* end = last;
	end = end->prev;
	while(end != first)
	{
		delete end->next;
		end = end->prev;	
	}
	delete first;
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	if(size == 0)
		return true;
	else 
		return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	if(index<0 || index >size-1)
		return *last;
	DroneRecord* ptr = first;
	for(int i =0; i<= index; i++)
		ptr = ptr->next;
	return *(ptr->prev);
	// what to return if the size of the list is zero
}

unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* ptr = first;
	int index =0; 
	while(ptr!= NULL && !(*ptr == value ))
	{
		ptr = ptr->next;
		index++;
	}
	if(ptr == NULL)
		return size;
	return index;
}

void DronesManager::print() const {
	cout<< droneID <<"  "<<range<<" "<< yearBought <<" "<< droneType<<" "<<manufacturer<<
	"  "<<description<<"  "<<batteryType<<endl;
}



bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	if(lhs.droneID == rhs.droneID && lhs.range = rhs.range && lhs.yearBought==rhs.yearBought && 
	lhs.droneType == rhs.droneType && lhs.manufacturer == rhs.manufacturer && 
	lhs.description == rhs.description && lhs.batteryType == rhs.batteryType)
		return true;
	else
		return false;
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if(index == 0 && size ==1)
		insert_front(value);
	else if(index == size-1)
		insert_back(value);
	else if(index >0 && index <size-1){
		DroneRecord* ptr1 = first;
		DroneRecord* ptr2 = first->next;
		int listIndex = 1;
		while(listIndex!= index){
			ptr1 = ptr2;
			ptr2 = ptr2->next;
			listIndex++;
		}
		ptr1->next = new DroneRecord(value);
		ptr1->next->prev = ptr1;
		ptr1->next->next = ptr2;
		ptr2->prev = ptr->next;	
		size++;
		return true;
	}
	return false;
}

bool DronesManager::insert_front(DroneRecord value) {
	if(size ==0){
		first = new DroneRecord(value);
		last = first;
		first->prev = NULL;
		first->next = NULL;
		size++;
		return true;
	}
	else if(size>0){
		first->prev = new DroneRecord(value);
		first->prev->next = first;
		first = first->prev;
		first->prev = NULL;
		size++;
		return true;
	}
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	if(size ==0){
		first = new DroneRecord(value);
		last = first;
		first->prev = NULL;
		first->next = NULL;
		size++;
		return true;
	}
	else if (size>0){
		last->next = new DroneRecord(value);
		last->next->prev = last;
		last = last->next;
		last->next = NULL;
		size++;
		return true;
	}
	return false;
}

bool DronesManager::remove(unsigned int index) {
	DroneRecord* ptr1 = first;
	DroneRecord* ptr2 = first->next;
	if(index == 0 && size ==1)
		remove_front();
	else if (index == size-1)
		remove_back();
	else if(index>0 && index< size-1){
		int listIndex = 0;
		while(listIndex != index){
			ptr1 = ptr2;
			ptr2 = ptr2->next;
			listIndex++
		}
		DroneRecord* ptr3 = ptr1->prev;
		delete ptr3->next;
		ptr3->next = ptr2;
		ptr2->prev = ptr3;
		size--;
		return true;
	}
	return false;
}

bool DronesManager::remove_front() {
	if(size>1){
		DroneRecord* newFirst = first->next;
		delete first;
		first = newFirst;
		first->prev = NULL;
		size--;
		return true;
	}
	else if (size == 1)	{
		delete first;
		first = NULL;
		last = NULL;
		size--;
		return true;
	}
	return false;
}

bool DronesManager::remove_back() {
	if(size>1){
		DroneRecord* newLast = last->prev;
		delete last;
		last = newLast;
		last->next = NULL;
		size--;
		return true;
	}
	else if(size == 1){
		delete last;
		first = last = NULL;
		size--;
		return true;
	}
	return false;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if(remove(index) ==true && insert(value, index) == true)
		return true;
	return false;
}

bool DronesManager::reverse_list() {
	DroneRecord* ptr = last;
	last = first;
	first = ptr;
	while(ptr != NULL){
		DroneRecord* temp = ptr->prev;
		ptr->prev = ptr->next;
		ptr->next = temp;
		ptr = ptr->next;
	}
	if(ptr == NULL)
		return true;
	return false;
}

bool DronesManagerSorted::is_sorted_asc() const {

	return false;
}

bool DronesManagerSorted::is_sorted_desc() const {
}

bool DronesManagerSorted::insert_sorted_asc(DroneRecord val) {
	return false;
}

bool DronesManagerSorted::insert_sorted_desc(DroneRecord val) {
	return false;
}

void DronesManagerSorted::sort_asc() {
	DroneRecord* current = first;
	for(int i = 0; i<size; i++){
		DroneRecord* now = current;
		for(int j=1; j<size-i){
			now = now->next;
			if(current->droneID > now->droneID){
				insert(*now,i);
				remove(i+1);
				insert(*current,j);
				remove(j+1);
			}
		}
		current = current->next;
	}
}
    
void DronesManagerSorted::sort_desc() {
		DroneRecord* current = first;
	for(int i = 0; i<size; i++){
		DroneRecord* now = current;
		for(int j=1; j<size-i){
			now = now->next;
			if(current->droneID < now->droneID){
				insert(*now,i);
				remove(i+1);
				insert(*current,j);
				remove(j+1);
			}
		}
		current = current->next;
	}
}
