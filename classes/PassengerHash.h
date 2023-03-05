#include <iostream>
#include <list>
#include <vector>
#ifndef passenger_hash_h
#define passenger_hash_h
using namespace std;
class PassengerHash{    //a class called passgenger hash
   public:
      static const int BUCKET = 25;
      struct Passenger{ //a data struct called passenger and sotring all the datavariable type
         int ID;
         string Name;
         string Phone;
         Passenger* next = NULL;
      };
      PassengerHash();
      Passenger* passenger_table [BUCKET];    //a table getting all the values from passenger
      void display();
      int hash(string Name);
      void insert(int ID, string Name, string Phone);
      int items_in_bucket(int bucket);
      void delete_passenger(string Name);
      void update_passenger(string Name, int new_ID, string new_phone);
      void write(string filepath);
      void select_passenger(string Name);
};
#endif
