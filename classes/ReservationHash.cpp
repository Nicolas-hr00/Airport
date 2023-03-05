#include <iostream>
#include <iomanip>
#include <fstream>
#include "../classes/ReservationHash.h"
using namespace std;

ReservationHash::ReservationHash() {			//this is a parametarized constructor that is going to help us out to know if there is any values that is empty or not by using default variables
	for(int i=0; i < BUCKET; i++)
	{
        reservation_table[i] = new Reservation;
        reservation_table[i] -> PassID = -1;
        reservation_table[i] -> FLNO = -1;
        reservation_table[i] -> FDate = "empty";
        reservation_table[i] -> FromA = "empty";
        reservation_table[i] -> ToA = "empty";
        reservation_table[i] -> SeatClass = "empty";
        reservation_table[i] -> DateBooked = "empty";
        reservation_table[i] -> DateCancelled = "N/A";
        reservation_table[i] -> next = NULL;
	}
}
int ReservationHash::hash(int FLNO) {		//we are going to be using stringging hashing and chaining to help us out to sove the collition problem
    string iter = to_string(FLNO);		//we know that the key is going to be the name
	int hash = 0;
	for (int i = 0; i < iter.length(); i++) {
		hash = (127 * hash + iter[i]) % BUCKET;
	}
    return hash;
}
void ReservationHash::insert(int PassID, int FLNO, string FDate, string FromA, string ToA, string SeatClass, string DateBooked, string DateCancelled) {// we are going to pass the data vairables and we are going to be using the name as the key to access al the data variables
	int bucket = hash(FLNO);
	if (reservation_table[bucket] -> FDate == "empty") {		//we are actually using the parametarized constructor to check if tehre is any value in case there is not any value we  going to store values
		reservation_table[bucket] -> PassID = PassID;
        reservation_table[bucket] -> FLNO = FLNO;
        reservation_table[bucket] -> FDate = FDate;
        reservation_table[bucket] -> FromA = FromA;
        reservation_table[bucket] -> ToA = ToA;
        reservation_table[bucket] -> SeatClass = SeatClass;
        reservation_table[bucket] -> DateBooked = DateBooked;
        reservation_table[bucket] -> DateCancelled = DateCancelled;
        reservation_table[bucket] -> next = NULL;
	} else {
		Reservation* curr_res = reservation_table[bucket];		//this is a pointer bucker that is creating a current object
		Reservation* new_res = new Reservation;		//and we dinamically allocate the values
		new_res -> PassID = PassID;
        new_res -> FLNO = FLNO;
        new_res -> FDate = FDate;
        new_res -> FromA = FromA;
        new_res -> ToA = ToA;
        new_res -> SeatClass = SeatClass;
        new_res -> DateBooked = DateBooked;
        new_res -> DateCancelled = DateCancelled;
        new_res -> next = NULL;
		while(curr_res->next != NULL) {		//as long as the current values is not equal to null we are going to kepe storing values
			curr_res = curr_res->next;
		}
		curr_res->next = new_res;		//once we get out of the while we move on to the next one
	}
}
int ReservationHash::items_in_bucket(int bucket) {		//the items in the bucket is going to check the actuall values that there are in the bucket and see if it is not equal to null
	int i = 0;		//this is going to tell us how many items there are in the bucket, or people in the same index
	if (reservation_table[bucket] -> FDate == "empty") {
		return i;
	} else {
		i++;
		Reservation* curr_res = reservation_table[bucket];
		while(curr_res -> next != NULL)
		{
           i++;
           curr_res = curr_res -> next;
		}
	}
	return i;
}
void ReservationHash::display() {		//this function is going to display all the data wee need
    for (int bucket=0; bucket < BUCKET; bucket++)
	{
        int total = items_in_bucket(bucket);		//by using the total suize of the bucket it is going to access to the data we store it before
        cout << "-----------------------" << endl;
        cout << "Index = " << bucket << endl;
		cout << "First Reservation of index:" << endl;
        cout << "PassID: " << reservation_table[bucket] -> PassID << endl;
        cout << "FLNO: " << reservation_table[bucket] -> FLNO << endl;
        cout << "Flight Date: " << reservation_table[bucket] -> FDate << endl;
        cout << "Flight Origin: " << reservation_table[bucket] -> FromA << endl;
        cout << "Flight Destination: " << reservation_table[bucket] -> ToA << endl;
        cout << "Seat Class: " << reservation_table[bucket] -> SeatClass << endl;
        cout << "Date Booked: " << reservation_table[bucket] -> DateBooked << endl;
        cout << "Date Cancelled: " << reservation_table[bucket] -> DateCancelled << endl;
        cout << "# of items = " << total << endl;
        cout << "-----------------------" << endl;
	}
}
void ReservationHash::delete_reservation(int PassID, int FLNO) {	//this function is going to help us to delete the data from he indexes
	int bucket = hash(FLNO);
	Reservation* curr_res = reservation_table[bucket];
	Reservation* del_res;
	Reservation* p1;
	Reservation* p2;

	if (reservation_table[bucket] -> FDate == "empty") {		//in case that the variable is empty it tells us that the reservation could not be found
		cout << "A reservation with Pass ID " << PassID << " and FLNO " << FLNO << " could not be found" << endl;
	} else if (reservation_table[bucket] -> PassID == PassID and reservation_table[bucket] -> FLNO == FLNO and reservation_table[bucket] -> next == NULL) // this is going to be for the same
	{
        int i = bucket;
		reservation_table[i] -> PassID = -1;
        reservation_table[i] -> FLNO = -1;
        reservation_table[i] -> FDate = "empty";
        reservation_table[i] -> FromA = "empty";
        reservation_table[i] -> ToA = "empty";
        reservation_table[i] -> SeatClass = "empty";
        reservation_table[i] -> DateBooked = "empty";
        reservation_table[i] -> DateCancelled = "empty";
		cout << "Reservation with Pass ID " << PassID << " and FLNO " << FLNO << " was removed" << endl;
	}
	else if (reservation_table[bucket] -> PassID == PassID and reservation_table[bucket] -> FLNO == FLNO)		//in case that we found the data we are looking for the data is going to be removed
	{
        del_res = reservation_table[bucket];
        reservation_table[bucket] = reservation_table[bucket] -> next;
        delete del_res;
        cout << "Reservation with Pass ID " << PassID << " and FLNO " << FLNO << " was removed" << endl;
	}
	else
	{
		p1 = reservation_table[bucket]-> next;
		p2 = reservation_table[bucket];

		while(p1 != NULL &&  (p1 -> PassID != PassID or p1 -> FLNO != FLNO))
		{
			p2 = p1;
			p1 = p1 -> next;
		}
		if(p1 == NULL)
		{
			cout << "A reservation with Pass ID " << PassID << " and FLNO " << FLNO << " could not be found" << endl;
		}
		else
		{
			del_res = p1;
			p1 = p1-> next;
			p2 -> next = p1;

			delete del_res;
			cout << "Reservation with Pass ID " << PassID << " and FLNO " << FLNO << " was removed" << endl;
		}
	}
}
//the update function is going to check if the function is empty or not and let us know, but also it is going to check if the values i not equal to the null and let us modify the value. Them, it is going to move to the next value
void ReservationHash::update_reservation(int  curr_resID, int curr_FLNO, string new_FDate, string new_FromA, string new_ToA, string new_SeatClass, string new_DateBooked, string new_DateCancelled) {
	int bucket = hash(curr_FLNO);
	Reservation* curr_res = reservation_table[bucket];
	if (reservation_table[bucket] -> FDate == "empty") {
		cout << "A reservation with Pass ID " <<  curr_resID << " and FLNO " << curr_FLNO << " could not be found" << endl;
	} else {
		while((curr_res->PassID !=  curr_resID or curr_res->FLNO != curr_FLNO) and curr_res != NULL) { // if it is not equal to noo it moves tothe next values
			curr_res = curr_res->next;
		}
		if (curr_res == NULL) {
			cout << "A reservation with Pass ID " <<  curr_resID << " and FLNO " << curr_FLNO << " could not be found" << endl;
		} else {
			curr_res->FDate = new_FDate;
			curr_res-> FromA = new_FromA;
            curr_res-> ToA = new_ToA;
            curr_res-> SeatClass = new_SeatClass;
            curr_res-> DateBooked = new_DateBooked;
            curr_res-> DateCancelled = new_DateCancelled;
			cout << "The Reservation was updated successfully" << endl;
		}
	}
}
void ReservationHash::write(string filepath) {		//this function is going to help us out to write to a file.
	ofstream out_file(filepath);
	if (out_file.fail()) {
		cout << "Could not access output file" << endl;
		exit(EXIT_FAILURE);
	}
	Reservation* curr_res;
	out_file << "Bucket, PassID, FLNO, FDate, FromA, ToA, SeatClass, DateBooked, DateCancelled" << endl;  //this is all the data that is going to be passed to a file
	for (int i = 0; i < BUCKET; i++) {
		curr_res = reservation_table[i];
		while(curr_res != NULL) {
			if (curr_res->FLNO != -1) {
				out_file << i << ", " << curr_res->PassID << ", " << curr_res->FLNO << ", " << curr_res->FDate << ", " << curr_res->FromA << ", " << curr_res->ToA << ", " << curr_res->SeatClass << ", " << curr_res->DateBooked << ", " << curr_res->DateCancelled << endl;
			}
			curr_res = curr_res->next;
		}
	}
	out_file.close();	//this is going to close the file
}
void ReservationHash::select_reservation(int PassID, int FLNO) {		//the select function is going to check if we find the value or not. Otherwise, it is going to let us pick the passenger ewe are looking for
	int bucket = hash(FLNO);
	Reservation* curr_res = reservation_table[bucket];
	if (reservation_table[bucket] -> FDate == "empty") {
		cout << "The reservation was not found in the passenger table" << endl;
	} else {
		while((curr_res->PassID != PassID or curr_res->FLNO != FLNO) and curr_res != NULL) {
			curr_res = curr_res->next;
		}
		if (curr_res == NULL) {
			cout << "The reservation was not found in the passenger table" << endl;
		} else {
			cout << "The reservation was found in bucket " << bucket << endl;
			cout << "PassID: " <<  curr_res -> PassID << endl;
            cout << "FLNO: " <<   curr_res -> FLNO << endl;
            cout << "Flight Date: " <<   curr_res -> FDate << endl;
            cout << "Flight Origin: " <<   curr_res -> FromA << endl;
            cout << "Flight Destination: " <<   curr_res -> ToA << endl;
            cout << "Seat Class: " <<   curr_res -> SeatClass << endl;
            cout << "Date Booked: " <<   curr_res -> DateBooked << endl;
            cout << "Date Cancelled: " <<   curr_res -> DateCancelled << endl;
		}
	}
}
