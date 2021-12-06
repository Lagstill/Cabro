
#include"Driver.h"

#include <iostream>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;


void Driver::D_add()
{


    cout<<"INPUT THE FOLLOWING DETAILS :"<<endl;
    cout<<"********************************"<<endl;
    cin.clear();
    char r[5];
    cout<<"\nNAME :\t";
    cin.getline(r,5);
    cin.getline(D_name,30);
    cout<<"GENDER[m/f] :\t";
    cin.getline(D_gender,30);
    cout<<"\nSHIFT[m/n] :\t";
    cin.getline(D_shift,30);
    cout<<"\nE-mail :\t";
    cin.getline(D_mail,30);
    cout<<"\nPHONE NUMBER :\t";
    cin.getline(D_phone,12);
    cin.clear();
    cout<<"\nSALARY :\t";
    cin>>sal;

    Create_file4();


}

void Driver::Create_file4()
{
    fstream book;

    book.open("Driver.csv", ios::out | ios::app);
    book
            << D_name<< ", "
            <<D_gender<< ", "

            << D_shift<< ", "
            <<D_mail<<", "
            << D_phone<< ", "
            <<sal
            << "\n";

}
void Driver::D_show(int x)
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

    fin.open("Driver.csv");


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

    for(int k=0; k<c; k=k+7)
    {

        if(i==x)
        {
            h=k;
            g=0;
            cout<<"\nLOGIN SUCCESSFULL..."<<endl;

            cout<<"\nNAME        :\t\t\t"<<row[k]
                <<"\nSHIFT       :\t\t\t"<<row[k+2]<<
                "\nGENDER       :\t\t\t"<<row[k+1]<<
                "\nMAIL         :\t\t\t"<<row[k+3]<<
                "\nPHONE NUMBER :\t\t\t"<<row[k+4]<<
                "\nSALARY       :\t\t\t"<<row[k+5]<<","<<row[k+6]<<

                "\n------------------------------------------------------------"<<endl;

        }
        i++;
    }

    if(g!=0)
    {
        cout<<"\nID NOT FOUND"<<endl;
    }
}




