
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{


    int Reg_id;
    char Phone_num[12];
    char Name[30];
    char U_name1[30];
    char Pass1[10];
    char City[30];
    char Credit_no[20];
    char Address[50];
    int Pay_mode;
    char ch;

public:
    int C_search(char* id);

    void Ins_1();
    void Update_1();
    void Set_id();
    int Get_id();
    void Set_paym();
    char Get_paym();
    void Create_file();
    void For_b();

};

#endif

