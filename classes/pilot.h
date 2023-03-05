#pragma once
// #include"../main/libraries.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Pilot {
    public:
        PilotTable(int size);      //default constructor

        void readPilotFile(string filePilot);       //read file Data_Pilot.CSV
        void displayPilot();

//milestone 2
        // void insert();
        // void update();
        // void select();
        // void delete();

        int moduloHash(int IDKey);       //hash fx type //modulo fx to get bucket

    private:
        class PilotEntry {      //set up for linear probing
            public:
                int ID;
                string name;
                string dateHired;
                bool emptySinceStart = true;        //initialize empty since start //for search and delete
                bool emptyAfterRemoval = false;     //initialize empty after removal //for search and delete
        }

        string filePilot, IDKey;
        vector<PilotEntry> bucketsPilot;
        int sizePilot;
};
