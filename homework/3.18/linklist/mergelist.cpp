//
// Created by User on 2024-03-19.
//
#include "def.h"
#include "linklist.h"

LIST mergelist(const LIST& l1,const LIST& l2)
{
    int len1 = 0;
    LIST l3 = l1->next;
    while(l3->next != NULL)
    {
        l3 = l3->next;
        len1++;
    }
    len1++;

    int len2 = 0;
    LIST l4 = l2->next;
    while(l4->next != NULL)
    {
        l4 = l4->next;
        len2++;
    }
    len2++;

    LIST l = createnull(len1+len2);
    LIST t = l->next;
    int i = 0;

    int j=0,k=0;

    LIST m = l1->next;
    LIST n = l2->next;
    while((m->next!=NULL)&&(n->next!=NULL))
    {
        if((m->data)<=(n->data))
        {
            t->data = m->data;
            m = m->next;
            j++;
        }
        else
        {
            t->data = n->data;
            n = n->next;
            k++;
        }
        t = t->next;
    }

    int flag1 = 0;
    int flag2 = 0;
    while(flag1 != 1 && flag2 != 1)
    {
        if(m->data<=n->data)//其中一个等于NULL的最后一次情况
        {
            if(m->next == NULL)
            {
                flag1++;
            }
            t->data=m->data;
            m=m->next;
            j++;
        }
        else
        {
            if(n->next == NULL)
            {
                flag2 ++;
            }
            t->data=n->data;
            n=n->next;
            k++;
        }
        t=t->next;
    }
    /*
    if((m->data)<=(n->data))
    {
        t->data = m->data;
        m = m->next;
        j++;
    }
    else
    {
        t->data = n->data;
        n = n->next;
        k++;
    }
    t = t->next;
     */

    if(j > len1-1)
    // l1 full
    {
        int cy = len2 - k;
        for(int u = 0;u < cy;u++)
        {
            t->data = n->data;
            t = t->next;
            n = n->next;
        }
    }

    if(k > len2-1)
        // l1 full
    {
        int cy = len1 - j;
        for(int u = 0;u < cy;u++)
        {
            t->data = m->data;
            t = t->next;
            m = m->next;
        }
    }

    return l;
}