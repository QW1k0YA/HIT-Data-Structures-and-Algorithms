//
// Created by User on 2024-03-18.
//
#include <iostream>
using namespace std;
#include "def.h"
#include "seqlistoper.h"

LIST mergelist(const LIST& l1,const LIST& l2)
{
    LIST l;
    l.last = l1.last + l2.last + 1;
    int i = 0;

    int j=0,k=0;

    while((j <= l1.last)&&(k <= l2.last))
    {
        if(l1.elements[j] <= l2.elements[k])
        {
            l.elements[i] = l1.elements[j];
            i++;
            j++;
        }
        else
        {
            l.elements[i] = l2.elements[k];
            i++;
            k++;
        }
    }

    if(j > l1.last)
    {
        int cy = l2.last - k + 1;
        for(int n = 0;n < cy;n++)
        {
            l.elements[i] = l2.elements[k];
            i++;
            k++;
        }
    }

    if(k > l2.last)
    {
        int cy = l1.last - j +1;
        for(int n = 0;n < cy;n++)
        {
            l.elements[i] = l1.elements[j];
            i++;
            j++;
        }
    }

    return l;
}