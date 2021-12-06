#include"Admin.h"

#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include<ctime>
#include <iostream>

using namespace std;


string convertToString(char* a, int size)
{
    string s = a;
    return s;
}

void Admin::A_show_s(int g)
{
    S.S_show(g);
}

void Admin::A_show_d(int g)
{
    D.D_show(g);
}

void Admin::A_add_d()
{
    D.D_add();
}

void Admin::A_add_s()
{
    S.S_add();
}

void  Admin::Assign()
{

    cin.clear();
    vector<string> row;
    string line, word, temp,rollnum;
    ifstream fin;
    int c=0;
    int s;
    int t;

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

    int m=1;
    for(int k=0; k<c; k=k+9)
    {
        cout<<"\n*S.NO              :  ["<<m<<"]"<<endl;
        cout<<"\nID                 :\t\t\t "<<row[k+1]
            <<"\nNAME               :\t\t\t"<<row[k+2]<<


            "\nTRAVEL TIME        :\t\t\t "<<row[k+6]<<

            "\nDISTRICT OF TRAVEL :\t\t\t"<<row[k+8]<<
            "\nDATE               :\t\t\t "<<row[k]<<
            "\n------------------------------------------------------------"<<endl;
        m++;
    }

    int p=0;
    cout<<"\nENTER THE S.NO. OF THE RECORD TO GENERATE THE PAYMENT LIST\n";
    cin>>p;
    m=1;
    int r=0;
    for(int k=1; k<c; k=k+9)
    {

        if(m==p)
        {
            r=k;
            break;
        }

        m++;

    }
   fin.close();

    vector<string> row1;

    ifstream ip;
    ip.open("Staff.csv",ios::in);
    c=0;
    while(!ip.eof())
    {
        getline(ip,line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            c++;
            row1.push_back(word);

        }
    }

s=1;

    for(int k=0; k<c; k=k+7)
    {

    string g=" ";
    g.append(row1[k]);

       if(row[r+7]==g || row1[k]==row[r+7])
        {

            s=k;
            break;
        }
        s++;
    }

ip.close();

vector<string> row2;
ip.open("Driver.csv");
c=0;
    while(!ip.eof())
    {
        getline(ip,line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            c++;
            row2.push_back(word);
        }
    }
m=0;
    for(int k=0; k<c; k=k+7)
    {
        if(m==D_count)
        {
            t=k;

            break;
       }
m++;
   }
   D_count++;
    fstream book;

    book.open("Payment statement.csv", ios::out | ios::app);


    time_t curr_time;
    tm * curr_tm;
    char date_string[100];


    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(date_string, 50, "%B|%d|%Y", curr_tm);
    stringstream geek(row[r+5]);
            int x = 0;
            geek >> x;

            tim=price*x;

    book <<date_string<< ", "
         << row[r]<< ", "
         <<row[r+2]<< ", "
        << row[r+7]<< ", "
         <<row[r+3]<<", "
         <<tim<< ", "
       <<row2[t]<<", "
         <<row2[t+4]<<", "
        <<row1[s+2]<<", "
   <<row1[s+3]
         << "\n";
}

int Admin::D_count=0;

void Admin::Bill()
{
    cout<<"\nENTER THE CAB FARE PER HOUR\n";
    cin>>price;
}
