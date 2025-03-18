//
// Created by User on 2024-03-19.
//
#include "def.h"
#include "linklist.h"

void inverselist(LIST l)
{
    //insert!!
    LIST p,q;
    p = l->next;
    q = p->next;

    if(p)
    {
        q = p->next;
        p->next = NULL;
        while(q != NULL)
        {
            p = q;
            q = q->next;
            p->next = l->next;
            l->next = p;
        }
        // p q are always out of the breakpoint
    }
}