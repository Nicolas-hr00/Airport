#include <iostream>
#include <list>
#include <vector>
#ifndef reservation_hash_h
#define reservation_hash_h
using namespace std;
class ReservationHash{  //clas reservation
    public:
        static const int BUCKET = 25;
        struct Reservation{ //a struct c4alled reservation so we can access to the variables
            int PassID = -1;
            int FLNO = -1;
            string FDate;
            string FromA;
            string ToA;
            string SeatClass;
            string DateBooked;
            string DateCancelled;
            Reservation* next;
        };
        Reservation* reservation_table [BUCKET];
        ReservationHash();
        void display();
        int hash(int FLNO);   //these are all the different implementations that we going to be using like insert, delete, items in the bucket, update, write and select
        void insert(int PassID, int FLNO, string FDate, string FromA, string ToA, string SeatClass, string DateBooked, string DateCancelled);
        int items_in_bucket(int bucket);
        void delete_reservation(int PassID, int FLNO);
        void update_reservation(int curr_PassID, int curr_FLNO, string new_FDate, string new_FromA, string new_ToA, string new_SeatClass, string new_DateBooked, string new_DateCancelled);
        void write(string filepath);
        void select_reservation(int PassID, int FLNO);
};
#endif
