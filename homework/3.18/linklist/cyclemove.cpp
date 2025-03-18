//
// Created by User on 2024-03-19.
//
#include "def.h"
#include "linklist.h"

void cyclemove(LIST l,int num,bool isleft)
{
    int len = 0;
    LIST l1 = l->next;
    while(l1->next != NULL)
    {
        l1 = l1->next;
        len++;
    }
    len++;

    l1->next = l->next;

    LIST l2,l3;
    l3 = l1->next;
    if(isleft)
    {
        for(int i = 0;i < num-1;i++)
        {
            l3 = l3->next;
        }
        l->next = l3->next;
        l3->next = NULL;
    }
    else
    {
        for(int i = 0;i < len - num - 1;i++)
        {
            l3 = l3->next;
        }
        l->next = l3->next;
        l3->next = NULL;
    }

}