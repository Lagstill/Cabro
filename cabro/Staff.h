#ifndef STAFF_H
#define STAFF_H
#include<iostream>
#include"Driver.h"



using namespace std;

class Staff
{
    Driver dr;

    char S_name[30];
    char S_mail[30];
    char S_phone[12];
    char S_dept[30];
    int tot;
    float sal;
public:
    void S_add();

    void S_show(int j);
    void Create_file3();
    void S_show_d(int g);

};

#endif
