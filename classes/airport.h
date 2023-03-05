#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
// #include"../main/libraries.h"
using namespace std;

class Airport {
    public:
        AirportTable(int size);      //default constructor

        void readAirportFile(string fileAirPort);       //read file Data_AirPort.
        void displayAir();

//milestone 2
        // void insert();
        // void update();
        // void select();
        // void delete();

        int multiplicativeHash(string codeKey);       //fx to get bucket

    private:
        /*class AirEntry {        //set up for chaining
            public:
                int code;
                string city;
                string state;
        }
        */
        string fileAirPort, codeKey;
        vector<AirEntry> bucketsAir;
        int sizeAir;

};
