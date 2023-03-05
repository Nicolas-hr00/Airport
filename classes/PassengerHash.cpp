#include <iostream>
#include <iomanip>
#include <fstream>
#include "../classes/PassengerHash.h"
using namespace std;
PassengerHash::PassengerHash() {		//this is going to be a parametarized constructor with default variables
	for(int i=0; i < BUCKET; i++)
	{
		passenger_table[i] = new Passenger;
		passenger_table[i] -> ID = -1;
		passenger_table[i] -> Name = "empty";
		passenger_table[i] -> Phone = "empty";
		passenger_table[i] -> next = NULL;
	}
}
int PassengerHash::hash(string Name) {		//stirnging hashing is going to be used and chaining method to avoid collision
	int hash = 0;
	for (int i = 0; i < Name.length(); i++) {
		hash = (127 * hash + Name[i]) % BUCKET;
	}
    return hash;
}
void PassengerHash::insert(int ID, string Name, string Phone) {	//The inser functions is going to insert all the values in case that the values are being empty on theconstructor
	int bucket = hash(Name);
	if (passenger_table[bucket] -> Name == "empty") {
		passenger_table[bucket] = new Passenger;
		passenger_table[bucket]->ID = ID;
		passenger_table[bucket]->Name = Name;
		passenger_table[bucket]->Phone = Phone;
		passenger_table[bucket]->next = NULL;
	} else {
		Passenger* curr_pass = passenger_table[bucket];
		Passenger* new_pass = new Passenger;
		new_pass->ID = ID;
		new_pass->Name = Name;
		new_pass->Phone = Phone;
		new_pass->next = NULL;
		while(curr_pass->next != NULL) {
			curr_pass = curr_pass->next;
		}
		curr_pass->next = new_pass;	//after finishing the while loop we are going to move to the next value
	}
}
int PassengerHash::items_in_bucket(int bucket) {	//this is going to tell us how many items we have on the same index
	int i = 0;
	if (passenger_table[bucket] -> Name == "empty") {
		return i;
	} else {
		i++;
		Passenger* curr_pass = passenger_table[bucket];
		while(curr_pass -> next != NULL)
		{
           i++;
           curr_pass = curr_pass -> next;
		}
	}
	return i;
}
void PassengerHash::display() {		//this is going to display all the values
    for (int i=0; i < BUCKET; i++)
	{
        int total = items_in_bucket(i);
        cout << "-----------------------" << endl;
        cout << "Index = " << i << endl;
		cout << "First Passenger of index:" << endl;
		cout << "ID: " << passenger_table[i] -> ID << endl;
        cout << "Name: " << passenger_table[i] -> Name << endl;
		cout << "Phone: " << passenger_table[i] -> Phone << endl;
        cout << "# of items = " << total << endl;
        cout << "-----------------------" << endl;
	}
}
void PassengerHash::delete_passenger(string Name) {		//delete passenger is going to chekc if there is any value on the index and let us know. Otherwise, it is going to grab thevalues and delete it deppending what the user is looking for
	int bucket = hash(Name);
	Passenger* curr_pass = passenger_table[bucket];
	Passenger* del_pass;
	Passenger* p1;
	Passenger* p2;

	bool found_name = false;

	if (passenger_table[bucket] -> Name == "empty") {
		cout << Name << " was not found in the passenger table " << endl;
	} else if (passenger_table[bucket] -> Name == Name and passenger_table[bucket] -> next == NULL)
	{
		passenger_table[bucket] -> ID = -1;
		passenger_table[bucket] -> Name = "empty";
		passenger_table[bucket] -> Phone = "empty";
		cout << Name  << " was removed from the hash table " << endl;
	}
	else if (passenger_table[bucket] -> Name == Name)
	{
		del_pass = passenger_table[bucket];
		passenger_table[bucket] = passenger_table[bucket] -> next;
		delete del_pass;
		cout << Name << " was removed from the hash table " << endl;
	}
	else
	{
		p1 = passenger_table[bucket]-> next;
		p2 = passenger_table[bucket];

		while(p1 != NULL &&  p1 -> Name != Name)
		{
			p2 = p1;
			p1 = p1 -> next;
		}
		if(p1 == NULL)
		{
			cout << Name << " was not found in the hash table " << endl;
		}
		else
		{
			del_pass = p1;
			p1 = p1-> next;
			p2 -> next = p1;

			delete del_pass;
			cout << Name << " was removed from the hash table " << endl;
		}
	}
}

void PassengerHash::update_passenger(string Name, int new_ID, string new_phone) {	//this is going to update the passengers eitehr way they are there or not, and let us know if they are there or not
	int bucket = hash(Name);
	Passenger* curr_pass = passenger_table[bucket];
	if (passenger_table[bucket] -> Name == "empty") {
		cout << Name << " was not found in the passenger table " << endl;
	} else {
		while(curr_pass->Name != Name and curr_pass != NULL) {
			curr_pass = curr_pass->next;
		}
		if (curr_pass == NULL) {
			cout << Name << " was not found in the passenger table " << endl;
		} else {
			curr_pass->ID = new_ID;
			curr_pass->Phone = new_phone;
			cout << Name << " was updated with ID " << new_ID << " and Phone " << new_phone << endl;
		}
	}
}
void PassengerHash::write(string filepath) { 	//This is going to write all the data into the files
	ofstream out_file(filepath);
	if (out_file.fail()) {
		cout << "Could not access output file" << endl;
		exit(EXIT_FAILURE);
	}
	Passenger* curr_pass;
	out_file << "Bucket, ID, Name, Phone" << endl;
	for (int i = 0; i < BUCKET; i++) {
		curr_pass = passenger_table[i];
		while(curr_pass != NULL) {
			if (curr_pass->ID != -1) {
				out_file << i << ", " << curr_pass->ID << ", " << curr_pass->Name << ", " << curr_pass->Phone << endl;
			}
			curr_pass = curr_pass->next;
		}
	}
	out_file.close();	//this is going to close the file
}
void PassengerHash::select_passenger(string Name) { 	//this is going to select the passenger either way if the passenger exits or not 
	int bucket = hash(Name);
	Passenger* curr_pass = passenger_table[bucket];
	if (passenger_table[bucket] -> Name == "empty") {
		cout << Name << " was not found in the passenger table " << endl;
	} else {
		while(curr_pass->Name != Name and curr_pass != NULL) {
			curr_pass = curr_pass->next;
		}
		if (curr_pass == NULL) {
			cout << Name << " was not found in the passenger table " << endl;
		} else {
			cout << Name << " was found in bucket " << bucket << endl;
			cout << "ID: " << curr_pass->ID << endl;
			cout << "Phone: " << curr_pass->Phone << endl;
		}
	}
}
