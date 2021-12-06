#ifndef DRIVER_H
#define DRIVER_H
#include<iostream>


class Driver
{

    char D_name[30];
    char D_mail[30];
    char D_gender[30];
    char D_shift[30];
    char D_phone[12];
    float sal;

public:
    void D_add();

    void Create_file4();
    void D_show(int x);

};

#endif
