
#ifndef ADMIN_H
#define ADMIN_H

#include"Staff.h"
#include"Driver.h"

class Admin
{


    char id[4];
    char loc[30];
    char lisc_p[30];

    char dept[30];
   int tim;
    char d_name[30];
    char s_name[30];
    char d_num[30];
    char s_num[30];
    int ch;
    int i;
    Staff S;
    Driver D;
    float price;

public:
    Admin()
    {
        ch=1;
    }
    static int D_count;
    void A_add_s();
    void A_add_d();
    void A_show_s(int g);
    void A_show_d(int g);
    void Bill();
    void Assign();

};


#endif
