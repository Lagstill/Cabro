#include"Booking.h"

#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include<ctime>
#include <iostream>


using namespace std;


void Booking::B_add(char* id)
{
    cin.ignore();
    cin.clear();
    char r[5];
    cout<<"INPUT THE FOLLOWING DETAILS :"<<endl;
    cout<<"********************************"<<endl;
    cout<<"\nNAME :\t";
    cin.getline(U_name3,30);
    cout<<"\nENTER THE DISTRICT OF TRAVEL:\t";
    cin.getline(Dist,30);
    strcpy(ID,id);
    cin.clear();
    cout<<"\nPICK-UP LOC. :\t";
    cin.getline(Pick,40);
    cout<<"\nTOTAL NUMBER OF TRAVELLORS :\t";
    cin>>P_tot;
    cout<<"\nDROP LOC. :\t"<<endl;
    cin.clear();
    cin.getline(r,5);
    cin.getline(Drop,40);
    C_mode(P_tot);
    cout<<"\nTOTAL TRAVEL TIME [in hours] :\t";
    cin.getline(P_time,20);
    Create_file2();


}
void Booking::Create_file2()
{
    fstream book;

    book.open("Bookings.csv", ios::out | ios::app);


    time_t curr_time;
    tm * curr_tm;
    char date_string[100];


    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(date_string, 50, "%B|%d|%Y", curr_tm);

    book <<date_string<<", "
         <<ID<<", "
         <<U_name3<<", "

         <<Pick<<", "
         <<Lisc<<", "
         <<Drop<<", "
         <<P_time<<", "
         <<B_mod<<", "
         <<Dist
         << "\n";

}
void Booking::C_mode(int x)
{
    cout<<"\n--------------------------------------"<<endl;
    cout<<"\nHere's the list of cars available"<<endl;
    cout<<"\n--------------------------------------"<<endl;

    ifstream ip("Car.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Not Open" << '\n';
    string car_m,cap,fin;
    while(ip.good())
    {
        getline(ip,car_m,',');
        getline(ip,cap,',');
        getline(ip,fin,'\n');
        stringstream geek(cap);
        int z=0;
        geek>>z;
        if(z==x )
        {
            cout<<"\n---------------------------------------------------\n";
            cout<<"\nCAR_MODEL                  : "<<car_m<<"\nCAPACITY                   : "<<cap;
            cout<<"\n---------------------------------------------------\n";
        }
    }
    ip.close();
car:
    cout<<"\nENTER THE CAR MODEL"<<endl;
    cin.getline(B_mod,40);
    vector<string> row;
    string line, word, temp;
    ifstream file;
    int c=0;
    int g=1;

    file.open("Car.csv");
    while(!file.eof())
    {
        getline(file,line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            c++;
            row.push_back(word);

        }
    }

    for(int k=0; k<c; k=k+3)
    {

        if(row[k]==B_mod)
        {


            g=0;
            cout<<"\nMODEL AVAILABLE!!!\n";
            strcpy(Lisc, row[k+2].c_str());

        }
    }


    if(g!=0)
    {

        cout<<"\nNO MODEL AVAILABLE !"<<"OR THE CAPACITY IS NOT APPROPRAIATE!!\n";
        goto car;

    }
    file.close();
}


void Booking::B_show(char* id)
{
    cout<<"\n***THE ENTERED RECORD***"<<endl;

    cin.ignore();
    cin.clear();

    vector<string> row;
    string line, word, temp,rollnum;
    ifstream fin;
    int c=0;
    int g=1;
    int h=0;

    fin.open("Bookings.csv");


    while(!fin.eof())
    {
        getline(fin,line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            c++;
            row.push_back(word);


        }
    }


    for(int k=0; k<c; k=k+9)
    {

        string s=" ";
        s.append(id);
        if(row[k+1]==s)
        {
            h=k;
            g=0;
            cout<<"\nLOGIN SUCCESSFULL..."<<endl;

            cout<<"\nID                :\t\t\t  "<<row[k+1]
                <<"\nNAME              :\t\t\t"<<row[k+2]<<
                "\nPICK UP LOC.      :\t\t\t"<<row[k+3]<<
                "\nVEHICLE REGISTRATION NUMBER        :\t"<<row[k+4]<<
                "\nDROP LOC.         :\t\t\t"<<row[k+5]<<
                "\nTRAVEL TIME      :\t\t\t "<<row[k+6]<<
                "\nMODEL [FOR DRIVE] :\t\t\t"<<row[k+7]<<
                "\nDISTRICT OF TRAVEL:\t\t\t"<<row[k+8]<<
                "\nDATE              :\t\t\t "<<row[k]<<
                "\n------------------------------------------------------------"<<endl;

        }
    }

    if(g)
    {
        cout<<"\nID NOT FOUND"<<endl;
    }

}
void Booking::B_pay(char* id)
{
    cout<<"\n***THE ENTERED RECORD***"<<endl;

    cin.ignore();
    cin.clear();

    vector<string> row;
    string line, word, temp,rollnum;
    ifstream fin;
    int c=0;
    int g=1;
    int h=0;

    fin.open("Payment statement.csv");


    while(!fin.eof())
    {
        getline(fin,line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            c++;
            row.push_back(word);


        }
    }


    for(int k=0; k<c; k=k+10)
    {
string s=" ";
        s.append(id);
        string d= "  ";
        d.append(id);

        if(row[k+1]==s || row[k+1]==id ||row[k+1]==d)
        {
            h=k;
            g=0;
            cout<<"\nLOGIN SUCCESSFULL..."<<endl;

            cout<<"\nID                         :\t\t\t "<<row[k+1]
                <<"\nDRIVER NAME                :\t\t\t"<<row[k+6]<<
                  "\nDRIVER NUMBER              :\t\t\t"<<row[k+7]<<
                  "\nVEHICLE REGISTRATION NUMBER:\t\t\t"<<row[k+4]<<
                  "\nIN-CHARGE STAFF NAME       :\t\t\t"<<row[k+8]<<
                  "\nIN-CHARGE STAFF NUMBER     :\t\t\t"<<row[k+9]<<
                  "\nAMOUNT [Rs.]               :\t\t\t "<<row[k+5]<<

                "\n------------------------------------------------------------"<<endl;

        }
    }

    if(g)
    {
        cout<<"\nID NOT YET PLACED FOR RIDE CALCULATION"<<endl;
    }
}

int Booking::B_search(char* id)
{
    strcpy(ID,id);

    return C_search(id);
}




