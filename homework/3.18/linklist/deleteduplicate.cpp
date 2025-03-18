//
// Created by User on 2024-03-19.
//
#include "def.h"
#include "linklist.h"

void deleteduplicate(LIST l)
{
    LIST p = l;
    LIST pp = p->next->next;
    int i = 1;
    while(pp->next != NULL)
    {
        if(p->next->data == pp->data)
        {
            pp = pp->next;
            deletelocate(l,i);
            i--;
        }
        // n1->  [n2-> delete] n3 i=2
        // n1->  n2   n3    ->n4 i =2
        //n1 ->    n3    ->n4 i = 2
        else
        {
            pp = pp->next;
            p = p->next;
        }
        i++;
    }

    if(p->next->data == pp->data)
    {
        pp = pp->next;
        deletelocate(l,i);
    }



}