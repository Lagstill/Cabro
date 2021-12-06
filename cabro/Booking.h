#ifndef BOOKING_H
#define BOOKING_H

#include"Customer.h"

class Booking:public Customer
{
    char P_time[20];
    char Pick[40];
    char Drop[40];
    char B_mod[40];
    int P_tot;
    char Dist[30];
    char U_name3[30];
    char Lisc[20];
    char ID[4];
    char id[4];

public:
    void B_add(char* id);
    void B_show(char* id);

    void B_pay(char* id);
    int B_search(char* id);
    void C_mode(int x);
    void Create_file2();
    friend class Driver;

};

#endif
