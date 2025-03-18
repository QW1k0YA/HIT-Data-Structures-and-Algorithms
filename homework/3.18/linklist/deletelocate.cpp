//
// Created by User on 2024-03-18.
//
#include "def.h"

void deletelocate(LIST l,int n)
{
    LIST ptr,p = NULL;
    ptr = l->next;
    for(int i = 0;i < n-2;i++)
    {
        ptr = ptr->next;
    }
    //n1 ->(ptr)n2 n3 n4

    p = ptr->next;
    //n1 ->(ptr)n2 ->(p)n3 n4

    ptr->next = p->next;
    free(p);

}