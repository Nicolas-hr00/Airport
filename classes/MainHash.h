#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "PassengerHash.h"
#include "ReservationHash.h"
using namespace std;
#ifndef main_hash_h
#define main_hash_h
class MainHash{   //this public class is going to help to read, insert, display,update,select,delete and write
    public:
        PassengerHash pass_hash; //these two objects are goign to be the ones that are going to carry the variables
        ReservationHash res_hash;

        void read_files(string pass_filepath, string res_filepath);
        void INSERT(string input, string table_name);
        void DISPLAY();
        void UPDATE(string input, string table_name);
        void SELECT(string input, string table_name);
        void DELETE(string input, string table_name);
        void WRITE();
};
#endif
