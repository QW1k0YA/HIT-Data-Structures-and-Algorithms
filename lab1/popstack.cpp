//
// Created by User on 2024-03-25.
//
#include "Stack.h"

char popstack(STACK &S)
{
    char result = S.elements[S.top];
    if(S.top < 0)
    {
        cout <<"empty!";
    }
    else
    {
        S.top--;
    }

    return result;
}

int popstack_(STACK_ &S)
{
    int result = S.elements[S.top];
    if(S.top < 0)
    {
        cout <<"empty!";
    }
    else
    {
        S.top--;
    }

    return result;
}