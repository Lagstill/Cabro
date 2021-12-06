#include"Feedback.h"

#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

void Feedback::Set_cont(char *id)
{
    cin.ignore();
    cin.clear();

    cout<<"\nDO ENTER YOUR FEEDBACK...\nYOUR WORDS-OUR IMPROVEMENT"<<endl;
    cin.getline(Cont,90);
    cout<<"**************************\n\t\t\tTHANKYOU\n*************************"<<endl;
    ofstream fi("Feedback.txt",ios::app);
    if(fi.is_open())
    {
        fi<<"FEED : "<<Cont<<" ^ID :"<<id<<"\n\n";
        fi.close();
    }
    else
    {
        cout<<"FILE NOT OPEN"<<endl;
    }

}
