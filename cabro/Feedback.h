#ifndef FEEDBACK_H
#define FEEDBACK_H


#include"Customer.h"

class Feedback:virtual public Customer
{
    char Cont[90];

public:


    void Set_cont(char* id);
};


#endif
