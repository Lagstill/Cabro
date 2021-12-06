#include"Payment.h"

#include <iostream>
#include<string.h>

using namespace std;

void Payment::P_add()
{
    cout<<"INPUT THE FOLLOWING DETAILS :"<<endl;
    cout<<"********************************"<<endl;
    cout<<"\nCUSTOMER ID :\t";
    cin.getline(C_id,30);
    cout<<"\nNAME :\t";
    cin.getline(C_name,30);

    cout<<"\nDATE :\t"<<endl;
    cin.getline(C_date,20);
    cout<<"\nAMOUNT :\t"<<endl;
    cin>>C_amount;

}


char* Payment::Get_id()
{
    return C_id;
}
void Payment::P_show()
{
    cout<<"\n***THE PAYMENT RECORD***\n"<<endl;
    cout<<"\nCUSTOMER ID  :\t"<<C_id<<
        "\nNAME         :\t"<<C_name<<
        "\nDATE         :\t"<<C_date<<
        "\nAMOUNT       :\t"<<C_amount<<

        "\n------------------------------------------------------------"<<endl;
}


