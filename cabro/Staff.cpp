
#include"Staff.h"


#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>

#include <iostream>


using namespace std;
using namespace std;

void Staff::S_add()
{
    cout<<"INPUT THE FOLLOWING DETAILS :"<<endl;
    cout<<"********************************"<<endl;
    cin.clear();
    char r[5];
    cout<<"\nNAME :\t";
    cin.getline(r,5);
    cin.getline(S_name,30);
    cout<<"DEPARTMENT :\t";
    cin.getline(S_dept,30);
    cout<<"\nE-MAIL :\t";
    cin.getline(S_mail,30);
    cout<<"\nPHONE NUMBER :\t";
    cin.getline(S_phone,12);
    cin.clear();
    cout<<"\nSALARY :\t";
    cin>>sal;
    cout<<"\nENTER THE TOTAL NUMBER OF DRIVERS UNDER CONTROL :\t";
    cin>>tot;
    Create_file3();


}

void Staff::Create_file3()
{
    fstream book;

    book.open("Staff.csv", ios::out | ios::app);
    book
            << S_dept<< ", "
            <<S_mail<< ", "

            << S_name<< ", "
            <<S_phone<<", "
            << tot<< ", "
            <<sal
            << "\n";

}


void Staff::S_show(int j)
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

    fin.open("Staff.csv");


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

    int i=0;
    j=j-1;
    for(int k=0; k<c; k=k+7)
    {

        if(i==j)
        {
            h=k;
            g=0;
            cout<<"\nLOGIN SUCCESSFULL..."<<endl;

            cout<<"\nDEPARTMENT          :\t\t\t"<<row[k]
                <<"\nNAME                :\t\t\t"<<row[k+2]<<
                "\nE-MAIL              :\t\t\t"<<row[k+1]<<
                "\nPHONE NUMBER        :\t\t\t"<<row[k+3]<<
                "\nNO. OF DRIVERS UNDER:\t\t\t"<<row[k+4]<<
                "\nSALARY              :\t\t\t"<<row[k+5]<<","<<row[k+6]<<

                "\n------------------------------------------------------------"<<endl;

        }
        i++;
    }

    if(g!=0)
    {
        cout<<"\nID NOT FOUND"<<endl;
    }
}

void Staff::S_show_d(int g)
{
    dr.D_show(g);
}

