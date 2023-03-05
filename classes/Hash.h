// #include <iostream>
#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
// #include"../main/libraries.h"
using namespace std;

class Hash  //A class function storing 3 different struct with their own datas
{
 private:
   static const int BUCKET = 25;  //we are going to have 3 data types with their own data object in order have access between each other. This help us out to not to use inheretance, it is an indirect way of not using inheretance
   struct PlaneSeats
    {
        string SeatType;
        string NoOfSeats;
        string Maker;
        string Model;
    };
   struct PlaneType
    {
       double FlyingSpeed;
       double GroundSpeed;
       string Maker;
       string Model;
       PlaneSeats Seats;    //This is going to store the maker and model into Seats
    };
   struct Plane
    {
       int ID;
       string LastMaint;
       string LastMaintA;
       Plane* next;        //Calling the object next
       PlaneType type;    //Creating an object from PlaneType that is going to store the maker and model of it so we can access to it
     };
  public:
   // void PrintInfo();
   Plane* table_plane[BUCKET];
   PlaneType* table_type[BUCKET];
   PlaneSeats* table_seats[BUCKET];
   Hash();
   void InserPlane(int ID, string Maker, string Model, string LastMaint,string LastMaintA);
   int HashFunction(string key);
   void PrintInfo();
};
