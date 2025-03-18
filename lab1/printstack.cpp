//
// Created by User on 2024-03-27.
//
#include "Stack.h"

void printstack(const STACK& s)
{
    for(int i = 0;i <= s.top;i++)
    {
        cout << s.elements[i]<< " " ;
    }
    cout << endl;
}

void printstack_(const STACK_& s)
{
    for(int i = 0;i <= s.top;i++)
    {
        cout << s.elements[i]<< " " ;
    }
    cout << endl;
}


