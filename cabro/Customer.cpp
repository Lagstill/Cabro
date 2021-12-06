#include"Customer.h"

#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include<sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;

void Customer::Ins_1()
{
    char r[5];
    cout<<"DO FILL CAUTIOSLY :"<<endl;
    cout<<"\n*************************************"<<endl;
    cout<<"\nFULL NAME :\t";
    cin.getline(r,5);
    cin.getline(Name,30);
    cout<<"\nPHONE NUMBER :\t";

    cin.getline(Phone_num,12);
    cout<<"\nDISTRICT :\t";
    cin.getline(City,30);
    cout<<"\nSET UP AN USERNAME :\t";
    cin.getline(U_name1,30);
write:
    cout<<"\nPASSWORD [Max.-10 char |EXCEPT ~'staff','admin'] :\t";
    cin.getline(Pass1,10);
    if(!strcmp(Pass1,"admin") || !strcmp(Pass1,"staff"))
    {
        cout<<"INCORRECT PASSWORD..."<<endl;
        goto write;
    }
    cout<<"\nPICK UP LOCATION[Eg:Nallur] :\t";
    cin.getline(Address,50);
    Set_id();
}


void Customer::Set_id()
{
    srand((unsigned) time(0));

    Reg_id = (rand() % 100) + 100;
    cout<<"\n**DO REMEMBER THIS :\n";
    cout<<"\nYOUR REGISTRATION ID IS :\t"<<Reg_id<<endl;
}

int Customer::Get_id()
{
    return Reg_id;
}

void Customer::Create_file()
{
    fstream cust;

    cust.open("Customer.csv", ios::out | ios::app);


    cust << Get_id()<< ", "
         << Pass1<< ", "

         << Name<< ", "
         <<City<<", "
         << Get_paym()<< ", "
         <<Address
         << "\n";

}

void Customer::Set_paym()
{
    int cho;
    char r[5];
    cout<<"\n\nENTER THE MODE OF PAYMENT :";
    cout<<"\n\n1~CREDIT CARD\n2~ON-RIDE\n"<<endl;
    cin>>cho;
    if(cho==1)
    {
        cout<<"ENTER THE CREDIT CARD NUMBER :\t";
        cin.getline(r,5);
        cin.getline(Credit_no,20);
        ch='p';
    }
    else
    {
        ch='o';
    }
    cout<<"\nTHANKYOU!:-D\n";
}


char Customer::Get_paym()
{
    return ch;
}

int Customer::C_search(char* id)
{
    vector<string> row;
    string line, word, temp,rollnum;
    ifstream fin;
    int c=0;
    int g=1;
    int h=0;

    fin.open("Customer.csv");

    // strcpy(Reg_id,id);

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

    //strcpy(ID,id);
    for(int k=0; k<c; k=k+6)
    {

        if(row[k]==id)
        {
            h=k;
            g=0;
            return h;
        }
    }

    if(g!=0)
    {
        return -1;
    }
    return h;
}


void Customer::Update_1()
{
    cin.ignore();
    cin.clear();
    char id[4];
    cout<<"\n*FOR CONFIRMATION :\n"<<"\nENTER YOUR REGISTRATION ID :\t";
    cin.getline(id,4);
    int x=C_search(id);
    char* array[10][6]= {};
    cout<<x<<"//////"<<endl;
    if(x>-1)
    {
        cout<<"\nLOGIN SUCCESSFULL..."<<endl;
        ofstream out("Customer.csv");
        Ins_1();
        strcpy(array[x][0],Address);
        strcpy(array[x][1],Name);
        strcpy(array[x][2],Pass1);
        strcpy(array[x][3],Phone_num);
        strcpy(array[x][4],Credit_no);
        strcpy(array[x][5],id);

    }
    else
    {
        cout<<"\nID NOT FOUND"<<endl;
    }
}


