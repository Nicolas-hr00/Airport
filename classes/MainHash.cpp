#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "MainHash.h"
#include "PassengerHash.h"
#include "ReservationHash.h"
using namespace std;
void MainHash::INSERT(string input, string table_name) {
    if (table_name == "Passenger") {    //this is going to store all the data from the CSV files
        string ID;
        string Name;
        string Phone;
        stringstream ss(input);
        getline(ss, ID, ',');
        getline(ss, Name, ',');
        getline(ss, Phone, ',');
        pass_hash.insert(stoi(ID), Name, Phone);
    } else if (table_name == "Reservation") {   //all the data from passengr and reservation is being store into the variables and the variables created stringstream
        string PassID;
        string FLNO;
        string FDate;
        string FromA;
        string ToA;
        string SeatClass;
        string DateBooked;
        string DateCancelled;
        stringstream ss(input);
        getline(ss, PassID, ',');
        getline(ss, FLNO, ',');
        getline(ss, FDate, ',');
        getline(ss, FromA, ',');
        getline(ss, ToA, ',');
        getline(ss, SeatClass, ',');
        getline(ss, DateBooked, ',');
        getline(ss, DateCancelled);
        res_hash.insert(stoi(PassID), stoi(FLNO), FDate, FromA, ToA, SeatClass, DateBooked, DateCancelled);
    } else {
        cout << "Invalid table name." << endl;
    }
}
void MainHash::DISPLAY() {  //this is going to display the table
    cout << "Passenger Table" << endl;
    pass_hash.display();
    cout << endl << "Reservation Table" << endl;
    res_hash.display();
}
void MainHash::UPDATE(string input, string table_name) {  //the update function is going to check the variables and update them
    if (table_name == "Passenger") {
        string new_ID;
        string Name;
        string new_Phone;
        stringstream ss(input);
        getline(ss, Name, ',');
        getline(ss, new_ID, ',');
        getline(ss, new_Phone, ',');
        pass_hash.update_passenger(Name, stoi(new_ID), new_Phone);
    } else if (table_name == "Reservation") {
        string PassID;
        string FLNO;
        string new_FDate;
        string new_FromA;
        string new_ToA;
        string new_SeatClass;
        string new_DateBooked;
        string new_DateCancelled;
        stringstream ss(input);
        getline(ss, PassID, ',');
        getline(ss, FLNO, ',');
        getline(ss, new_FDate, ',');
        getline(ss, new_FromA, ',');
        getline(ss, new_ToA, ',');
        getline(ss, new_SeatClass, ',');
        getline(ss, new_DateBooked, ',');
        getline(ss, new_DateCancelled, ',');
        res_hash.update_reservation(stoi(PassID), stoi(FLNO), new_FDate, new_FromA, new_ToA, new_SeatClass, new_DateBooked, new_DateCancelled);
    } else {
        cout << "Invalid table name." << endl;
    }
}
void MainHash::SELECT(string input, string table_name) {  //the select function is going to access to the passenger and reservvation and select the variables depending if they are there or not
    if (table_name == "Passenger") {
        pass_hash.select_passenger(input);
    } else if (table_name == "Reservation") {
        string PassID;
        string FLNO;
        stringstream ss(input);
        getline(ss, PassID, ',');
        getline(ss, FLNO, ',');
        res_hash.select_reservation(stoi(PassID), stoi(FLNO));
    } else {
        cout << "Invalid table name." << endl;
    }
}
void MainHash::DELETE(string input, string table_name) {  //delete is going to delete what it need to be deleted depending on what the user wants
    if (table_name == "Passenger") {
        pass_hash.delete_passenger(input);
    } else if (table_name == "Reservation") {
        string PassID;
        string FLNO;
        stringstream ss(input);
        getline(ss, PassID, ',');
        getline(ss, FLNO, ',');
        res_hash.delete_reservation(stoi(PassID), stoi(FLNO));
    } else {
        cout << "Invalid table name." << endl;
    }
}
void MainHash::WRITE() {    //this is going to write into the 2 files passenger out and reservation out
    pass_hash.write("passenger_out.csv");
    res_hash.write("reservation_out.csv");
}
void MainHash::read_files(string pass_filepath, string res_filepath) {  //this is going to read the files and let us know if the files fail to open or not.
    ifstream pass_file(pass_filepath);
    ifstream res_file(res_filepath);
    if (pass_file.fail()) {
        cout << "Could not open " << pass_filepath << endl;
        exit(EXIT_FAILURE);
    }
    if (res_file.fail()) {
        cout << "Could not open " << res_filepath << endl;
        exit(EXIT_FAILURE);
    }
    int i = 0;
    int j = 0;
    while(!pass_file.eof()) {
        string input;
        getline(pass_file, input);
        if (i > 0 and input.length() > 1) {
            this->INSERT(input, "Passenger");
        }
        i++;
    }
    while(!res_file.eof()) {
        string input;
        getline(res_file, input);
        if (j > 0 and input.length() > 1) {
            this->INSERT(input, "Reservation");
        }
        j++;
    }
    pass_file.close();  //the files are being closed 
    res_file.close();
}
