//
// Created by User on 2024-03-25.
//
#include "Stack.h"

void pushstack(STACK &S,char n)
{
    if(S.top >= MAX - 1)
    {
        cout << "stack is full"<<endl;
    }
    else
    {
        S.top++;
        S.elements[S.top] = n;
    }
}

void pushstack_(STACK_ &S,int n)
{
    if(S.top >= MAX - 1)
    {
        cout << "stack is full"<<endl;
    }
    else
    {
        S.top++;
        S.elements[S.top] = n;
    }
}