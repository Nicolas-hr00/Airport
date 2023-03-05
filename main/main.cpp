#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../classes/PassengerHash.h"
#include "../classes/ReservationHash.h"
#include "../classes/MainHash.h"
using namespace std;
void Banner();
int main () {
    Banner();
    MainHash test_hash;
    test_hash.read_files("../data/DATA_Passenger.CSV","../data/DATA_Reservation.CSV");    //this is going to read the data passenger csv and the reservation. csv files
     test_hash.INSERT("1,John,(222)222-2222", "Passenger"); //the data fro the passenger is going to be inserted
    test_hash.DISPLAY();    //we are going to display everyhing
    test_hash.UPDATE("Jones,1,UPDATE", "Passenger");  //the update function is going toupdate the values
    test_hash.UPDATE("1,1000,UPDATE,LOG,INT,E,9/4/2002,N/A", "Reservation");
    test_hash.DELETE("Jones", "Passenger");
    test_hash.DELETE("1,1000","Reservation");
    int in;
    cout << "Continue: ";   //in case we want to continue adding the values
    cin >> in;
    test_hash.DISPLAY();    //it is goign to display
    test_hash.SELECT("Jones", "Passenger");   //we are going to be selecting
    test_hash.SELECT("1,1000", "Reservation");
    test_hash.WRITE();  //this function is going to write the data 

    return 0;
}

//=========================================================================================

void Banner()   //Un banner
 {
   cout << "+--------------------------------------------------------------+\n"
     << "|               Computer Science and Engineering               |\n"
     << "|            CSCE 2110 - Foundation of Data Structures         |\n"
       << "|                                                              |\n"
       << "|                  Project 1 Airport Simulation                |\n"
       << "|                                                              |\n"
       << "|                   Section 204 Group Members:                 |\n"
       << "|              Ajay Jayanth ajayjayanth@my.unt.edu             |\n"
       << "|            Eduardo Garcia eduardogarcia6@my.unt.edu          |\n"
       << "|             Gonzalo Franco gonzalofranco@my.unt.edu          |\n"
     << "|               Ivan Garcia ivangarcia4@my.unt.edu             |\n"
      << "|        Nicolas Rotunno nicolashidalgorotunno@my.unt.edu      |\n"
     << "+--------------------------------------------------------------+\n\n\n";
}
