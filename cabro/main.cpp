/***********************************************************
                CPP PACKAGE SUBMISSION
                      SEMESTER-II

              CAB-RO MANAGEMENT SYSTEM[TN]
                      DEVELOPED BY:
                  ALAGU PRAKALYA~19PD05
                   SAI PRAGATHI~19PD17

                          AMCS
                PSG COLLEGE OF TECHNOLOGY
************************************************************/



#include <iostream>
#include <ctime>
#include <stdlib.h>
#include<fstream>
#include<sstream>
#include<string.h>


#include"Staff.h"
#include"Booking.h"
#include"Feedback.h"
#include"Admin.h"

using namespace std;

void sleep(float seconds)
{
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    while(clock() < startClock+secondsAhead);
    return;
}

void date()
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t\t    |"<<tm.tm_mday<<"/"<<tm.tm_mon+1<<"/"<<tm.tm_year+1900<<"|\n\n";
}

void Exit()
{
    system("color 06");
    cout<<"EXITING ";
    for(int process=0; process<6; process++)
    {
        sleep(0.50);
        cout<<".";
    }
    exit(0);
}

int main()
{
    Customer c[10];
    Booking b[10];
    Feedback f;
    Staff s;

    Admin a;

    int y=0;

    system("color 06");
    date();
    sleep(2.0);
    system("color 03");
    cout<<"\t\t\t\t\t   WELCOME TO THE CAB~RO MANAGEMENT"<<endl;
    cout<<"\t\t\t\t\t*********************************\n";
    cout<<"\t\t\t\t\t           |TAMIL NADU|\n";
    cout<<"\t\t\t\t\t*********************************\n";
    int i=0;
    int dec;
    int g;
    int th=0;
    char id[4];
    char us[20];
    char ps[20];
    char r[5];

beginning:
    cout<<"\n---------------------------------------------------\n";
    cout<<"\n\n*CHOOSE ONE OF THE FOLLOWING OPT : \n\n";
    cout<<"\n\t\t\t\t\t1~REGISTRATION\n\t\t\t\t\t2~LOGIN\n\t\t\t\t\t3~EXIT"<<endl;
    cout<<"\n[* IF YOU ARE A CUSTOMER YOU COULD LOGIN ONLY AFTER REGISTRATION :)]\n";
    cin>>dec;
    switch(dec)
    {
    case 1:
        c[i].Ins_1();
        c[i].Set_paym();
        c[i].Create_file();
        i++;
        cout<<"UPLOADING......\n";
        //c[i].Update_1();
        break;
    case 2:

        cout<<"\nENTER THE USER-NAME :\t";
        cin.getline(r,5);
        cin.getline(us,20);
        cout<<"\nENTER THE PASSWORD :\t";
        cin.getline(ps,20);
        cin.clear();
        if(!strcmp(ps,"staff") )
        {
            if(!strcmp(us,"pass"))
            {
                first:
                cout<<"\nENTER ONE OF THE FOLLOWING INPUT :\n";
                cout<<"\noooooooooooooooooooooooooooooooooooooo\n";
                cout<<"\n\t\t\t\t\t1~DRIVER RECORD\n\t\t\t\t\t2~STAFF'S DETAILS\n\t\t\t\t\t3~EXIT\n";
                cin>>g;
                if(g==1)
                {
                    cout<<"\nENTER THE DRIVER'S ID :\t";
                    cin>>g;
                    s.S_show_d(g);
                    goto first;
                }
                else if(g==2)
                {
                    cout<<"\nENTER YOUR ID :\t";
                    cin>>g;
                    s.S_show(g);
                    goto first;
                }
                else
                {
                    goto beginning;
                }

            }
            else
            {
                cout<<"\nYOU ARE NOT THE RIGHT STAFF....GOTCHA!!!\n";
                Exit();

            }
        }
        else if(!strcmp(ps,"admin"))
        {
            if(!strcmp(us,"pass"))
            {
detail:
                cin.clear();
                cout<<"\nENTER ONE OF THE FOLLOWING INPUT :\n";
                cout<<"\noooooooooooooooooooooooooooooooooooooo\n";
                cout<<"\n\t\t\t\t\t1~DRIVER'S DETAILS\n\t\t\t\t\t2~STAFF'S DETAILS\n\t\t\t\t\t3~PAYMENTS & ASSIGNMENTS\n\t\t\t\t\t4~EXIT\n";
                cin>>g;
                switch(g)
                {
                case 1:
                    cout<<"\nENTER THE DRIVER'S ID :\t";
                    cin>>g;
                    cout<<"\n** ENTER\n\t1-VIEW THE DETAILS OF THE DRIVER\n\t2-ADD NEW DRIVER DETAILS\n";
                    cin>>dec;
                    if(dec==1)
                    {
                        a.A_show_d(g);
                    }
                    else
                    {
                        a.A_add_d();
                    }
                    break;
                case 2:
                    cout<<"\nENTER THE STAFF'S ID :\t";
                    cin>>g;
                    cout<<"\n** ENTER\n\t1-VIEW THE DETAILS OF THE STAFF \n\t2-ADD NEW STAFF DETAILS\n";
                    cin>>dec;
                    if(dec==1)
                    {
                        a.A_show_s(g);
                    }
                    else
                    {
                        a.A_add_s();
                    }
                    break;
                case 3:
                    a.Bill();
                    a.Assign();
                    cout<<"\nSUCCESSFULLY ASSIGNED!\n";
                    break;

                case 4:
                    goto beginning;
                    break;
                default:
                    break;
                }
                goto detail;
            }
            else
            {
                cout<<"\nYOU ARE NOT THE RIGHT ADMIN.....GOTCHA!!!\n";
                Exit();
            }
        }
        else
        {

            cout<<"\nENTER YOUR REGISTRATION ID :\t";
            cin.getline(id,4);

            if(b[y].C_search(id)>-1)
            {

                cin.clear();
                cin.ignore();
light:
                cout<<"\nENTER ONE OF THE FOLLOWING INPUT :\n";
                cout<<"\noooooooooooooooooooooooooooooooooooooo\n";
                cout<<"\n\t\t\t\t\t1~BOOKINGS\n\t\t\t\t\t2~FEEDBACK\n\t\t\t\t\t3~EXIT\n";
                cin>>g;

                switch(g)
                {
                case 1:
                    cout<<"\noooooooooooooooooooooooooooooooooooooo\n";
                    cout<<"\nENTER ONE OF THE FOLLOWING INPUT \n";
                    cout<<"\noooooooooooooooooooooooooooooooooooooo\n";
                    cout<<"\n\t\t\t\t\t1~BOOK A NEW RIDE\n\t\t\t\t\t2~SHOW BOOKED RIDE\n\t\t\t\t\t3~VIEW THE PAYMENT[bill]\n";
                    cin>>th;

                    if(th==1)
                    {
                        b[y].B_add(id);
                    }
                    else if(th==2)
                    {
                        b[y].B_show(id);
                    }
                    else
                    {
                        b[y].B_pay(id);
                    }
                    break;
                case 2:

                    f.Set_cont(id);
                    break;
                case 3:
                    goto beginning;
                    break;
                default:
                    break;
                }
                y++;
                cout<<"\nTHANKYOU\n";
                goto light;

            }
            else
            {
                cout<<"\nID NOT FOUND!\n";
            }
        }
        break;


    case 3:

        Exit();
        break;
    default:
        break;
    }

    goto beginning;
}
