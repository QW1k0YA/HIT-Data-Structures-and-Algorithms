//
// Created by User on 2024-03-19.
//
#include "def.h"

void printlist(const LIST& l)
{
    LIST p = l->next;
    while(p->next != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data;
    cout << endl;


}